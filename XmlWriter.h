#ifndef XmlWriter_H
#define XmlWriter_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class XmlWriter {
public:
    void write(const std::string);
    void writeopenTag(const std::string openTag);
    void writecloseTag(const std :: string closetag);
    void writeStartElementTag(const std::string startTag);
    void writeEndElementTag();
    void writeStartAttribute(const std::string outAttribute);
    void writeEndAttribute(const std::string outAttribute);
    void writeString(const std::string outString);
    void open();
    void close();
private:
    std::ofstream outFile;
    int indent;
    int openTags;
    int openElements;
    std::vector<std::string> tempOpenTag;
    std::vector<std::string> tempElementTag;
    std:: string myAdress = "C:\\Users\\batma\\OneDrive\\Masaüstü\\cpp\\shape\\shape\\shape.xml";
    const std::string openTag;
    const std::string startTag;
    const std::string outAttribute;
   
};

#endif