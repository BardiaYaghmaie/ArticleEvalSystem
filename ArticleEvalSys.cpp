#include <bits/stdc++.h>
using namespace std;

class User {
    string Username;
    string Password;

    public:
        void SetUsername(string _username) { Username = _username; }
        void SetPassword(string _password) { Password = _password; }


    friend class Article;
};
User Users[100];

class Article {
    string ArticleId;
    string ArticleTitle;
    User Author;

    public:
        void SetTitle(string _title) { ArticleTitle = _title; }
        void SetArticleId(string _articleId) { ArticleId = _articleId; }

   friend class User;
};
Article Articles[100];

void RegisterUser() {
    cout << "USER REGISTER PAGE" << endl;
    User tempUser;
    cout << "Username: ";
    string name;
    cin >> name;
    tempUser.SetUsername(name);
    cout << "Password: ";
    string pass;
    cin >> pass;
    tempUser.SetPassword(pass);
    cout << "Register Done!";
}
void RegisterArticle() {
    cout << "ARTICLE REGISTER PAGE" << endl;
    Article tempArticle;
    cout << "Title: ";
    string title;
    cin >> title;
    tempArticle.SetTitle(title);
    cout << "Article ID: ";
    string id;
    cin >> id;
    tempArticle.SetArticleId(id);
    cout << "Register Done!";
}



int main() {
    cout << "WELCOME TO ARTICLE EVAL SYSTEM";

    
}