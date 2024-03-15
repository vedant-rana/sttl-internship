#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BlogPost {
private:
    string title;
    string content;

public:
    BlogPost(const string& title, const string& content) : title(title), content(content) {}

    void display() const {
        cout << "Title: " << title << "\n";
        cout << "Content: " << content << "\n\n";
    }
};

class Blog {
private:
    vector<BlogPost> posts;

public:
    void addPost(const BlogPost& post) {
        posts.push_back(post);
    }

    void displayAllPosts() const {
        cout << "All Posts:\n";
        for (const auto& post : posts) {
            post.display();
        }
    }
};

int main() {
    Blog myBlog;

    myBlog.addPost(BlogPost("First Post", "This is the content of the first post."));
    myBlog.addPost(BlogPost("Second Post", "This is the content of the second post."));
    myBlog.addPost(BlogPost("Third Post", "This is the content of the third post."));

    myBlog.displayAllPosts();

    return 0;
}
