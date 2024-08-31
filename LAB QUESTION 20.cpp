#include <iostream>
#include <string>
#include <vector>

class Media {
protected:
    std::string title;
    bool issued;
public:
    Media(const std::string& title) : title(title), issued(false) {}

    virtual void display() const = 0;
    virtual void issue() {
        if (!issued) {
            issued = true;
            std::cout << title << " has been issued.\n";
        } else {
            std::cout << title << " is already issued.\n";
        }
    }
    virtual void deposit() {
        if (issued) {
            issued = false;
            std::cout << title << " has been deposited.\n";
        } else {
            std::cout << title << " was not issued.\n";
        }
    }

    std::string getTitle() const {
        return title;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    std::string author;
public:
    Book(const std::string& title, const std::string& author) : Media(title), author(author) {}

    void display() const override {
        std::cout << "Book: " << title << ", Author: " << author << "\n";
    }
};

class Tape : public Media {
private:
    double duration; // duration in minutes
public:
    Tape(const std::string& title, double duration) : Media(title), duration(duration) {}

    void display() const override {
        std::cout << "Tape: " << title << ", Duration: " << duration << " minutes\n";
    }
};

class DigitalLibrary {
private:
    std::vector<Media*> collection;
public:
    void addMedia(Media* media) {
        collection.push_back(media);
        std::cout << "Added new media: ";
        media->display();
    }

    void issueMedia(const std::string& title) {
        for (std::vector<Media*>::iterator it = collection.begin(); it != collection.end(); ++it) {
            if ((*it)->getTitle() == title) {
                (*it)->issue();
                return;
            }
        }
        std::cout << "Media with title " << title << " not found.\n";
    }

    void depositMedia(const std::string& title) {
        for (std::vector<Media*>::iterator it = collection.begin(); it != collection.end(); ++it) {
            if ((*it)->getTitle() == title) {
                (*it)->deposit();
                return;
            }
        }
        std::cout << "Media with title " << title << " not found.\n";
    }

    void displayAllMedia() const {
        for (std::vector<Media*>::const_iterator it = collection.begin(); it != collection.end(); ++it) {
            (*it)->display();
        }
    }

    ~DigitalLibrary() {
        for (std::vector<Media*>::iterator it = collection.begin(); it != collection.end(); ++it) {
            delete *it;
        }
    }
};

int main() {
    DigitalLibrary library;

    library.addMedia(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
    library.addMedia(new Tape("Inception", 120));

    std::cout << "\nDisplaying all media:\n";
    library.displayAllMedia();

    std::cout << "\nIssuing 'The Great Gatsby':\n";
    library.issueMedia("The Great Gatsby");

    std::cout << "\nDepositing 'The Great Gatsby':\n";
    library.depositMedia("The Great Gatsby");

    std::cout << "\nIssuing 'Inception':\n";
    library.issueMedia("Inception");

    std::cout << "\nDepositing 'Inception':\n";
    library.depositMedia("Inception");

    return 0;
}

