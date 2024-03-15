#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum FileType {
    FILE_TYPE,
    DIRECTORY_TYPE
};

class FileSystemNode {
public:
    string name;
    FileType type;
    vector<FileSystemNode*> children;

    FileSystemNode(const string& name, FileType type) : name(name), type(type) {}

    void addChild(FileSystemNode* child) {
        children.push_back(child);
    }
};

class FileSystem {
private:
    FileSystemNode* root;

    void printFileSystemHelper(FileSystemNode* node, int depth) {
        for (int i = 0; i < depth; ++i) {
            cout << "  "; 
        }

        cout << "|-- " << node->name;

        if (node->type == DIRECTORY_TYPE) {
            cout << " (Directory)";
        } else {
            cout << " (File)";
        }

        cout << "\n";

        for (FileSystemNode* child : node->children) {
            printFileSystemHelper(child, depth + 1);
        }
    }

public:
    FileSystem() {
        root = new FileSystemNode("Root", DIRECTORY_TYPE);
    }

    void addNode(const string& name, FileType type, const string& parentName) {
        FileSystemNode* newNode = new FileSystemNode(name, type);

        FileSystemNode* parentNode = searchNode(root, parentName);

        if (parentNode) {
            parentNode->addChild(newNode);
        } else {
            cout << "Error: Parent directory not found.\n";
            delete newNode;
        }
    }
    void printFileSystem() {
        printFileSystemHelper(root, 0);
    }

private:
    FileSystemNode* searchNode(FileSystemNode* currentNode, const string& nodeName) {
        if (currentNode->name == nodeName) {
            return currentNode;
        }
        for (FileSystemNode* child : currentNode->children) {
            FileSystemNode* result = searchNode(child, nodeName);
            if (result) {
                return result;
            }
        }

        return nullptr; 
    }
};

int main() {
    FileSystem fileSystem;

    fileSystem.addNode("Documents", DIRECTORY_TYPE, "Root");
    fileSystem.addNode("Images", DIRECTORY_TYPE, "Root");
    fileSystem.addNode("Work", DIRECTORY_TYPE, "Documents");
    fileSystem.addNode("Vacation.jpg", FILE_TYPE, "Images");
    fileSystem.addNode("Report.docx", FILE_TYPE, "Work");
    fileSystem.addNode("Personal", DIRECTORY_TYPE, "Root");
    fileSystem.addNode("Resume.pdf", FILE_TYPE, "Personal");

    fileSystem.printFileSystem();

    return 0;
}
