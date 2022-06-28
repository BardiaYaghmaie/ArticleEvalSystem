#include<bits/stdc++.h>
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
	//I think you forgot adding the function : "GetUsername" and "GetPassword" so i add it below
	string GetUsername() { return Username; }  
	string GetPassword() { return Password; }   
	friend class Article;
	//I added to below line :
	static int UserCount;
};
//User Users[100];
// i think it is better to have vector of user* . because we can handle some errors that may cause when we don't have any user woth specified id , username or password
vector<User*> Users;
//int UserCount = 0;
//instead of this , i use the following code
int User::UserCount = 0;  
class Article {

	int ArticleId;
	string ArticleTitle;
	//User Author;
	User* Author;  
	string Content;
	int ArticleCode;
	bool Acception;

public:
	void SetTitle(string _title) { ArticleTitle = _title; }
	void SetArticleId(int _articleId) { ArticleId = _articleId; }
	void SetContent(string _content) { Content = _content; }
	void SetArticleCode(int _articleCode) { ArticleCode = _articleCode; }
	// we should have function like : setAuthor and getAuthor
	User* GetAuthor() { return Author; }  
	void SetAuthor(User* _author) { Author = _author; }  
	// I do not understand why this method is here . Remember to explain this to me tomorrow
	bool IsArticleValid() {

		return true;
	}


	friend class User;
	friend bool ValidateArticle(Article a);
	static int ArticleCount;
};
//Article Articles[100];
//vector<Article> Articles;
// I really like to use pointers because we can use the "NULL" feature of pointers to conditionalize our code better I think
vector <Article*> Articles;  
//int ArticleCount = 0;
int Article::ArticleCount = 0;  
User* LoggedInUser = NULL;  


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
	cout << "Register Done!" << endl;
	//In my idea , i think it is a better idea to use a static field in User class instead of defining a global varible
	//tempUser.SetUserId(UserCount++);
	//Users[UserCount] = tempUser;
	//instead of the above code , we use the following (because of the using of an static field in class "User")
	User::UserCount++;   
	Users.push_back(&tempUser);  
}
// COMPLETE THIS FUCKIN TASK : ok.consider it done

User* FindUserByUsernameAndPassword(string username, string password) {
	for (int i = 0; i < Users.size(); i++)
	{
		if (Users.at(i)->GetUsername() == username && Users.at(i)->GetPassword() == password)
		{
			return Users[i];
		}
	}
	return NULL;
}
// I think it's necesssary to change the return type of the following function from void to boolean because there might be a possible senario where we can not authorize the user so we should handle this senario and for this we use boolean
//void LoginUser() {
bool LoginUser() {
	cout << "USER LOGIN PAGE" << endl;
	string username, password;
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> password;
	User* usr = FindUserByUsernameAndPassword(username, password);  
	if (!usr)     // this means that there is at least one user with the given details . so the user can log in
	{
		//i should write something here that logs the user in
		 // so i go up and define a global varibale named : "loggedInUser" which is of type User*;
		LoggedInUser->SetUserId(usr->GetUserId());  
		LoggedInUser->SetUsername(usr->GetUsername());  
		LoggedInUser->SetPassword(usr->GetPassword());  
		cout << "The user with id : " << LoggedInUser->GetUserId() << " and username : " << LoggedInUser->GetUsername() << " is logged in now !"<< endl;  
		return true;  
	}
	else {
		cout << "Login failed" << endl;  
		return false;  
	}

} 
//void RegisterArticle() {
bool RegisterArticle(){
	cout << "ARTICLE REGISTER PAGE" << endl;
	Article tempArticle;

	cout << "Title: ";
	string title;
	cin >> title;
	tempArticle.SetTitle(title);
	cout << "Article Code: ";
	int code;
	cin >> code;
	tempArticle.SetArticleCode(code);
	tempArticle.SetAuthor(LoggedInUser);  
	//tempArticle.SetArticleId(ArticleCount++);
	//Articles[ArticleCount] = tempArticle;
	Article::ArticleCount++;  
	tempArticle.SetArticleId(Article::ArticleCount);  
	if (ValidateArticle(tempArticle)) // check wether this temp article is valid or not . if it is valid , we add this article to the list otherwise we don't add this article to ther article's list
	{
		Articles.push_back(&tempArticle);  
		cout << "Register Done!";  
		return true;  
	}
	else {
		cout << "can not register this article";  
		Article::ArticleCount--; // because we ++ it in above lines but now because we do not regiser , we -- it
		return false;  
	}
	
	//tempArticle.Author.ArticleIDs(articleCount++);
}
bool ValidateArticle(Article article) {
	bool validTitle;
	bool validateContent;

    return 0;

}

int main() {
	cout << "WELCOME TO ARTICLE EVAL SYSTEM" << endl;
firstpage:
	cout << "1. Sign Up\t2. Login" << endl;
	int command;
	cin >> command;
	switch (command) {
	case 1:
		RegisterUser();
		//goto login;

	case 2:{
		bool flag = LoginUser();  
		if (flag)  
		{
			goto panel;

		}
		else {
			goto firstpage;
		}
	}
	default:
		cout << "Error: Unknown command!!";
		goto firstpage;
	}
panel:
	cout << "Panel";





}