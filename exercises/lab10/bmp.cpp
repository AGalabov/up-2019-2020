#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
struct Thumbnail
{
    string filename;
    string destination;
    int startX;
    int startY;
    int width;
    int height;
    Thumbnail(){};
    Thumbnail(string filename, string destination, int numbers[])
    {
        this->filename = filename;
        this->destination = destination;
        startX = numbers[0];
        startY = numbers[1];
        width = numbers[2];
        height = numbers[3];
    }
};
string clean(string c)
{
    string result(c);
    for (int i = 1; i < c.length(); i++)
    {
        if (c[i] == ';' && c[i - 1] == '\'' && c[i + 1] == c[i - 1])
        {
            if (c[i + 2] == ';')
                result.replace(i - 1, i, ";");
            else
            {
                result.replace(i - 1, i + 1, ";");
                cout << "Replaced!\n";
            }
        }
    }
    return result;
}
bool isComment(string line)
{
    if (line[0] == ';')
        return true;
    else
    {
        int i = 0;
        while (i < line.length())
        {
            int semicolon = line.find(';', i + 1);
            if (semicolon == -1)
                return false;
            else
            {
                if (!(line[semicolon - 1] == '\'' && (semicolon + 1 < line.length() && line[semicolon + 1] == '\'')))
                {
                    return true;
                }
                else
                    i = semicolon;
            }
        }
    }
}
Thumbnail *parseCorrect(string line)
{
    int marker = line.find(".bmp");
    if (marker == -1)
        return nullptr;
    string filename = line.substr(0, marker + 4);
    int firstClause = line.find('(', marker);
    int secondClause = line.find(')', firstClause);
    int numberCommas = 0;
    if (firstClause == -1 || secondClause == -1 || (secondClause - firstClause) < 0)
        return nullptr;
    for (int i = firstClause; i < secondClause; i++)
    {
        if (line[i] == ',')
            numberCommas++;
    }
    if (numberCommas != 3)
        return nullptr;
    int numbers[4];
    while (numberCommas > -1)
    {
        try
        {
            int nextComma = line.find(",", firstClause + 1);
            if (numberCommas == 0)
            {
                nextComma = line.find(")", firstClause + 1);
            }
            numbers[3 - numberCommas] = stoi(line.substr(firstClause + 1, nextComma));
            firstClause = nextComma;
            numberCommas--;
        }
        catch (invalid_argument e)
        {
            return nullptr;
        }
    }
    string destination = line.substr(line.find_first_not_of(" ", firstClause + 1));
    Thumbnail *result = new Thumbnail(filename, destination, numbers);
    return result;
}
string parseSubstring(char *line, int start, char delim)
{
    string result;
    for (int i = start; i < strlen(line) && line[i] != delim; i++)
    {
        result += line[i];
    }
    return result;
}
Thumbnail parse(char *line)
{
    Thumbnail result;
    char *c = new char[1];
    string name = parseSubstring(line, 0, '(');
}
int getInt(ifstream &file, int offset)
{
    file.seekg(offset);
    int result;
    file.read((char *)&result, sizeof(int));
    return result;
}
char **getColorMatrix(ifstream &f, int offset, int width, int height)
{
    int paddingLine = (4 - (width * 3) % 4) % 4;
    char **result = new char *[height];
    int pixels = 0;
    f.seekg(offset);
    for (int i = 0; i < height; i++)
    {
        result[i] = new char[width * 3];
        for (int j = 0; j < 3 * width; j += 3)
        {
            f.read(&result[i][j], sizeof(char));
            f.read(&result[i][j + 1], sizeof(char));
            f.read(&result[i][j + 2], sizeof(char));
        }
        f.seekg(f.tellg() + paddingLine);
    }
    return result;
}
void putColorMatrix(ofstream &writer, char **colors, int width, int height)
{
    int padding = (4 - (width * 3) % 4) % 4;
    writer.seekp(54);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 3; j++)
        {
            writer.write(&colors[i][j], sizeof(char));
        }
        char c = 0;
        for (int i = 0; i < padding; i++)
        {
            writer.write(&c, sizeof(char));
        }
    }
}
char **getSubColorMatrix(char **colors, int startX, int startY, int width, int height)
{
    char **result = new char *[height];
    cout << "Width:" << width << "Height:" << height << endl;
    for (int i = startY; i < startY + height; i++)
    {
        result[i - startY] = new char[width * 3];
        for (int j = 3 * startX; j < 3 * (startX + width); j++)
        {
            result[i - startY][j - 3 * startX] = colors[i][j];
        }
    }
    return result;
}
char *getHeader(ifstream &p)
{
    char *result = new char[54];
    p.seekg(0);
    p.read(result, 54 * sizeof(char));
    return result;
}
int getNewSize(int newWidth, int newHeight)
{
    int padding = (4 - (newWidth * 3) % 4) % 4;
    return newWidth * newHeight * 3 + 54 + padding * newHeight;
}
void putNewHeader(ofstream &writer, int newWidth, int newHeight, char *original)
{
    writer.seekp(0);
    writer.write(original, 54);
    writer.seekp(2);
    int newSize = getNewSize(newWidth, newHeight);
    writer.write((const char *)&newSize, sizeof(int));
    writer.seekp(18);
    writer.write((const char *)&newWidth, sizeof(int));
    writer.write((const char *)&newHeight, sizeof(int));
}
void generateThumbnail(const char *filename, int startX, int startY, int newWidth, int newHeight, const char *destination)
{
    ifstream p;
    p.open(filename, ios::binary);
    cout << "Generating thumbnail at: " << destination << endl;
    char *head = getHeader(p);
    int width = getInt(p, 18);
    int height = getInt(p, 22);
    if (startX < 0 || startY < 0 || (startX + newWidth - 1 > width) || (startY + newHeight - 1 > height))
    {
        cout << "Failed to generate thumbnail - proportions are either invalid (negative coordinates supplied) or bigger than the initial thumbnail.\n";
        return;
    }
    if (newWidth <= 0 || newHeight <= 0)
    {
        cout << "Couldn't generate thumbnail. Dimension is less or equal to zero";
        return;
    }
    char **color = getColorMatrix(p, 54, width, height);
    p.close();
    ofstream writer;
    writer.open(destination, ios::out | ios::binary);
    char **subColorMatix = getSubColorMatrix(color, startX, startY, newWidth, newHeight);
    putNewHeader(writer, newWidth, newHeight, head);
    putColorMatrix(writer, subColorMatix, newWidth, newHeight);
    writer.close();
}
void readTDF(const char *filename)
{
    ifstream reader;
    reader.open(filename, ios::in);
    if (!reader.is_open())
    {
        cout << "Couldn't open file";
        return;
    }
    while (!reader.eof())
    {
        string c;
        getline(reader, c);
        if (!isComment(c))
        {
            Thumbnail *paste = parseCorrect(c);
            if (paste == nullptr)
            {
                cout << "Incorrect line\n";
            }
            else
            {
                generateThumbnail(clean(paste->filename).c_str(), paste->startX, paste->startY, paste->width, paste->height, clean(paste->destination).c_str());
            }
        }
    }
}
int main()
{
    cout << "Please input tdf file:\n";
    string c;
    getline(cin, c);
    readTDF(c.c_str());
    return 0;
}
