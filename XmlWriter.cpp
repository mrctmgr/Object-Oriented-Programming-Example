#include "XmlWriter.h"
std::ofstream mfile;

void XmlWriter::open() {
	mfile.open(myAdress, std::ofstream::out | std::ofstream::app);
}
void XmlWriter::close() {
	mfile.close();
}
void XmlWriter::write(const std::string outString) {
	open();
	mfile << "<" << outString;
	close();
}
void XmlWriter:: writeopenTag(const std::string openTag) {
    open();
    for (int i = 0; i < indent; i++) {
        outFile << "\t";
    }
    tempOpenTag.resize(openTags + 1);
    mfile << "<" << openTag << ">\n";
    tempOpenTag[openTags] = openTag;
    indent += 1;
    openTags += 1;
    close();
}
void XmlWriter::writecloseTag(std::string closetag) {
    open();
        indent -= 1;
        for (int i = 0; i < indent; i++) {
            outFile << "\t";
        }
        mfile << "</" << closetag << ">\n";
        //tempOpenTag.resize(openTags - 1);
        openTags -= 1;
        close();
}
void XmlWriter::writeStartElementTag(const std::string elementTag) {
    open();
        for (int i = 0; i < indent; i++) {
            outFile << "\t";
        }
        tempElementTag.resize(openElements + 1);
        tempElementTag[openElements] = elementTag;
        openElements += 1;
        mfile << "\t<" << elementTag<<">\n";
        close();
}
void XmlWriter::writeEndElementTag() {
    open();
        mfile << "\t</" << tempElementTag[openElements - 1] << ">\n";
        tempElementTag.resize(openElements - 1);
        openElements -= 1;
        close();
}
void XmlWriter::writeStartAttribute(const std::string outAttribute) {
    open();
        mfile << "\t\t<" << outAttribute<<"> ";
        close();
    }
void XmlWriter::writeEndAttribute(const std::string outAttribute) {
    open();
    mfile << " </" << outAttribute << ">\n";
    close();
}
void XmlWriter::writeString(const std::string outString) {
    open();
    mfile  << outString;
    close();
}