#include <bits/stdc++.h>
using namespace std;

class User {
    int user_id;
    string Username;
    string Password;
    public: vector<int>ArticleIDs;

    public:
        void SetUsername(string _username) { Username = _username; }
        void SetPassword(string _password) { Password = _password; }
        void SetUserId(int _user_id) { user_id = _user_id; }
        int GetUserId() { return user_id; }


    friend class Article;
};
//User Users[100];
vector<User> Users;
int UserCount = 0;

class Article {
    string ArticleId;
    string ArticleTitle;
    User Author;
    bool Acception;

    public:
        void SetTitle(string _title) { ArticleTitle = _title; }
        void SetArticleId(string _articleId) { ArticleId = _articleId; }

   friend class User;
};
//Article Articles[100];
vector <Article> Articles;
int ArticleCount = 0;


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
    tempUser.SetUserId(UserCount++);
    Users[UserCount] = tempUser;
}
// void LoginUser() {}
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
    //tempArticle.Author.ArticleIDs(articleCount++);
}



int main() {
    cout << "WELCOME TO ARTICLE EVAL SYSTEM";

    

    
}