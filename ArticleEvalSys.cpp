#include<bits/stdc++.h>
// #include<iostream>
// #include<string>
// #include<vector>
// #include<algorithm>
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
	User Author;
	User Author2;
	string Content;
	int ArticleCode;

public:
	void SetTitle(string _title) { ArticleTitle = _title; }
	void SetArticleId(int _articleId) { ArticleId = _articleId; }
	void SetContent(string _content) { Content = _content; }
	void SetArticleCode(int _articleCode) { ArticleCode = _articleCode; }
    void SetAuthor2 (User _author) { Author2 = _author;}
    User GetAuthor2 () { return Author2; }
	string GetArticleContent() { return Content; }
	string GetArticleTitle() { return ArticleTitle; }
	// we should have function like : setAuthor and getAuthor
	User GetAuthor() { return Author; }
	void SetAuthor(User _author) { Author = _author; }
	// I do not understand why this method is here . Remember to explain this to me tomorrow
	bool IsArticleValid() {

		return true;
	}

    bool Acception;
    bool IsTeam;
	friend class User;
	friend bool ValidateArticle(Article* a);
	static int ArticleCount;
};
bool IsStrongPassword(string input) { 
    int n = input.length();
    // Checking lower alphabet in string
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, hasSpecialChar = false;
    string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            hasSpecialChar = true;
    }
    if (hasLower && hasUpper && hasDigit && hasSpecialChar)
        return true;

    return false;
    


}
//Article Articles[100];
//vector<Article> Articles;
// I really like to use pointers because we can use the "NULL" feature of pointers to conditionalize our code better I think
vector <Article*> Articles;
//int ArticleCount = 0;
int Article::ArticleCount = 0;
User LoggedInUser;

User* FindUserByUsername(vector<User*> users,string username) { 
 for (int i = 0; i < users.size(); i++) 
 { 
  if (users.at(i)->GetUsername()  == username) 
  { 
   return users.at(i); 
  } 
 } 
 return NULL; 
}

void RegisterUser() {
	cout << "\nUSER REGISTERATION PAGE\n" << endl;
	User* tempUser = new User();
	cout << "Username: ";
	string name;
	cin >> name;
	tempUser->SetUsername(name);
    setpassword:
    cout << "\nPassword Must Contain SpecialCharacter, Digits, Upper and Lower Cases" << endl;
	cout << "Password: ";
	string pass;
	cin >> pass;
	if (IsStrongPassword(pass)) {
        confirm:
        cout << "\nConfirm Password: ";
        string conf;
        cin >> conf;
        if (conf == pass)
            tempUser->SetPassword(pass);
        else {
            cout << "\n\t Passwords Do Not Match\n" << endl;
            goto confirm;

        }
    }
    else {
        cout << "\n\tInvalid Password\n" << endl;
        goto setpassword;
    }

	tempUser->SetUserId(User::UserCount);
	cout << "\n\tRegister Done!" << endl;
	//In my idea , i think it is a better idea to use a static field in User class instead of defining a global varible
	//tempUser.SetUserId(UserCount++);
	//Users[UserCount] = tempUser;
	//instead of the above code , we use the following (because of the using of an static field in class "User")
	User::UserCount++;

	Users.push_back(tempUser);
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
	cout << "\nUSER LOGIN PAGE\n" << endl;
	string username, password;
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> password;
	User* usr = FindUserByUsernameAndPassword(username, password);
	if (usr)     // this means that there is at least one user with the given details . so the user can log in
	{
		//i should write something here that logs the user in
		 // so i go up and define a global varibale named : "loggedInUser" which is of type User*;
		LoggedInUser.SetUserId(usr->GetUserId());
		LoggedInUser.SetUsername(usr->GetUsername());
		LoggedInUser.SetPassword(usr->GetPassword());
		//cout << "The user with id : " << LoggedInUser.GetUserId() << " and username : " << LoggedInUser.GetUsername() << " is logged in now !" << endl;
		cout << endl;
        return true;
	}
	else {
		cout << "\n\tLogin Failed\n" << endl;
		return false;
	}

}

void RegisterArticle() {
	cout << "\nARTICLE REGISTER PAGE\n" << endl;
	Article* tempArticle = new Article();
	cout << "Title: ";
	string title;
	string t;
	getline(cin, title);
	getline(cin, title);
	tempArticle->SetTitle(title);
	cout << "Article Code: ";
	int code;
	cin >> code;
	cout << "Article Content : ";
	string content, line;
	while (getline(cin, line)) {
		content += line + '\n';
		if (line == ";;;")
		{
			content.erase(content.end() - 5, content.end());
			break;
		}
	}



	tempArticle->SetContent(content);
	tempArticle->SetArticleCode(code);
	tempArticle->SetAuthor(LoggedInUser);
	//tempArticle.SetArticleId(ArticleCount++);
	//Articles[ArticleCount] = tempArticle;
	Article::ArticleCount++;
	tempArticle->SetArticleId(Article::ArticleCount);
    int choice; 
    cout << "Is This Article A Collaborator?" << endl;
    cout << "\n\t1. Yes\t2. No\n" << endl; 
    cin >> choice; 
    if (choice == 1) 
    { 
    cout << "Type the username of your collaborator : " << endl; 
    string uname; 
    cin >> uname; 
    User* usr = FindUserByUsername(Users,uname); 
    if (usr == NULL) 
    { 
     cout << "not found"; 
     tempArticle->IsTeam = false; 
    } 
    else { 
     tempArticle->SetAuthor2(*usr); 
     tempArticle->IsTeam = true; 
    } 
    } 
    
    else { 
     // do nothing 
     tempArticle->IsTeam = false; 
    }
	if (ValidateArticle(tempArticle)) // check wether this temp article is valid or not . if it is valid , we add this article to the list otherwise we don't add this article to ther article's list
	{
        cout << "\n\tArticle Registered Successfully\n" << endl;
        tempArticle->Acception = true;
	}
	else {
        cout << "\n\tArticle Rejected !!!\n" << endl;
        tempArticle->Acception = false;

	}
	Articles.push_back(tempArticle);


	//tempArticle.Author.ArticleIDs(articleCount++);
}
int getEditDistance(std::string first, std::string second)
{
	int m = first.length();
	int n = second.length();


	vector< vector<int> > T(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		T[i][0] = i;
	}

	for (int j = 1; j <= n; j++) {
		T[0][j] = j;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int weight = first[i - 1] == second[j - 1] ? 0 : 1;
			T[i][j] = std::min(std::min(T[i - 1][j] + 1, T[i][j - 1] + 1), T[i - 1][j - 1] + weight);
		}
	}

	return T[m][n];
}
double Similarity(string first, string second) {
	double max_length = std::max(first.length(), second.length());
	if (max_length > 0) {
		return (max_length - getEditDistance(first, second)) / max_length;
	}
	return 1.0;

}
//int WordCounter(Article* article) {
int WordCounter(string text) {
	int words = 0;

	int lenOfSentence = text.length();

	// run for loop from i = 0 to i = lenOfSentence
	// to iterate through each character of the string
	for (int i = 0; i < lenOfSentence; i++)
	{
		// check if current character is a space
		if (text[i] == ' ')
		{
			// if it is a space, increment word count
			words++;
		}

	}
	// at the end of the for loop, no. of spaces have been
	// counted. Increment word count one more time to get
	// no. of words
	words = words + 1;
	return words;

}
template<typename T>
bool IsxInArray(vector<T> arr, int x) {
	for (int i = 0; i < arr.size(); i++)
	{
		if (x == arr[i])
		{
			return true;
		}
	}
	return false;
}
//regex TO DO
//bool SpellChecker(string text) {
//	//check ; , :  ? !  - spells : 
//
//	bool flag1 = true;
//	for (int i = 0; i < text.length() - 1; i++)
//	{
//		if (
//			(text[i] == ';' && text[i + 1] == ';') ||
//			(text[i] == ':' && text[i + 1] == ':') ||
//			(text[i] == ',' && text[i + 1] == ',') ||
//			(text[i] == '?' && text[i + 1] == '?') ||
//			(text[i] == '!' && text[i + 1] == '!')
//			)
//		{
//			flag1 = false;
//		}
//	}
//	//check that there is capital letter after any dot and also at the first char of the text
//	bool flag2 = true;
//	bool flag2_ = isupper(text[1]);
//
//	size_t g = text.find(".");
//	while (g != string::npos)
//	{
//		//if (isupper(text[g + 1]) == false)
//		//{
//			//flag2 = false;
//			//break;
//		//}
//		char c = text[g + 1];
//		if (isalpha(c) == true)
//		{
//			if (isupper(c) == false)
//			{
//				flag2 = false;
//				break;
//			}
//			else {
//				text.erase(text.begin() + g);
//				g = text.find(".");
//			}
//		}
//		else {
//			text.erase(text.begin() + g);
//			g = text.find(".");
//		}
//	}
//	//check that there is an space after the . , ; : ( ) ? ! 
//	bool flag3 = true;
//	vector<char> v = { '.',';',':',')','(','?','!' };
//	for (int i = 0; i < text.length(); i++)
//	{
//		char x = text[i];
//		if (IsxInArray(v, x))
//		{
//			if (text[i + 1] == ' ' ||
//				(text[i + 1] == text.length() && text[text.length() - 1] == '.')
//				)
//			{
//				// do nothing
//			}
//			else {
//				flag3 = false;
//				break;
//			}
//		}
//	}
//	if (flag1 && flag2 && flag2_ && flag3)
//	{
//		return true;
//	}
//	else {
//		return false;
//	}
//
//}
vector <string> ConvertStringToArrayOfWords(string text) { 
size_t t = text.find("\n"); 
while (t != string::npos) 
{ 

 text.erase(text.begin() + t); 
 t = text.find("\n"); 
} 
// now all spaces are moved 
vector<string> wordsArr; 
t = text.find(" "); 
while (t != string::npos) 
{ 
 string x = text.substr(0, t); 
 wordsArr.push_back(x); 
 text.erase(0, t+1); 
 t = text.find(" "); 
} 
return wordsArr; 
}
int CountXInText(string x, string text) { 
vector<string> wordsArr = ConvertStringToArrayOfWords(text); 
// now er have the array of words; 
int counter = 0; 
for (int i = 0; i < wordsArr.size(); i++) 
{ 
if (x == wordsArr[i]) 
{ 
 counter++; 
} 
} 
return counter; 
}
bool ValidateArticle(Article* article) {
	//article content validation first
	bool flagArticleContent = true;
	if (Article::ArticleCount == 1)
	{
		//simply do nothing
		//return true;

	}
	else {
		for (int i = 0; i < Articles.size(); i++) {
			if (Articles[i] != article) {
				if (Similarity(article->GetArticleContent(), Articles[i]->GetArticleContent()) > 0.5)
					flagArticleContent = false;
				//return false;

			}
		}
	}
	if (WordCounter(article->GetArticleContent()) > 5000 || WordCounter(article->GetArticleContent()) < 100)
		flagArticleContent = false;
	//return false;

	// according to the project assignment  , the template should be at least 3 paragraphs
	bool flagParagraphCountCondition = true;
	string content = article->GetArticleContent();
	int counter = 0;
	size_t index_of_new_line = content.find("\n");
	while (index_of_new_line != string::npos)
	{
		counter++;
		content.erase(content.begin() + index_of_new_line);
		index_of_new_line = content.find("\n");
	}
	//counter--;
	if (counter < 3)
	{
		flagParagraphCountCondition = false;
	}
	// TITLE VALIDATION
	bool flagArticleTitle = true;
	if (WordCounter(article->GetArticleTitle()) > 12)
	{
		flagArticleTitle = false;
	}
    //validating that there is no words which has repeated more than 50 times 
    content = article->GetArticleContent(); 
    bool flagCountWordUnder50 = true; 
    vector<string>wordsArr = ConvertStringToArrayOfWords(content); 
    for (int i = 0; i < wordsArr.size(); i++) 
    { 
    string x = wordsArr[i]; 
    int countX = CountXInText(x, content); 
    if (countX > 50) 
    { 
    flagCountWordUnder50 = false; 
    break; 
    } 
 }
	// spell checking . just calling the function here : 
	//bool flagSpellChecker = SpellChecker(article->GetArticleContent());
	//total validation : 
	if (flagArticleContent && flagArticleTitle && flagParagraphCountCondition /*&& flagSpellChecker*/)
	{
		return true;
	}
	else {
		return false;
	}

 
}
void ShowAllArticles() { 
 if (Articles.size() <= 0) 
  cout << "\n\t404-No Articles Were Found\n" << endl; 
 else { 
  for (int i = 0; i < Articles.size(); i++) 
  { 
   string authors_text; 
   if (Articles[i]->IsTeam) 
   { 
    authors_text = Articles[i]->GetAuthor().GetUsername() + " , " + Articles[i]->GetAuthor2().GetUsername(); 
   } 
   else { 
    authors_text = Articles[i]->GetAuthor().GetUsername(); 
   } 
   if (Articles[i]->Acception) 
   { 
    cout << "\n\t[*]" << Articles[i]->GetArticleTitle() << "  By:  " <<authors_text << "  " << "Accepted\n" << endl; 
 
   } 
   else { 
    cout << "\n\t[*]" << Articles[i]->GetArticleTitle() << "  By:  " <<authors_text << "  " << "Rejected\n" << endl; 
 
   } 
 
  } 
 } 
}




int main() {
firstpage:
	cout << "\nWELCOME TO ARTICLE EVAL SYSTEM\n" << endl;
	cout << "\t1. Sign Up\t2. Login" << endl;
	int command;
	cin >> command;
	switch (command) {
	case 1:
		RegisterUser();
		goto login;

	case 2: {
	login:
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
	cout << "\n\tWelcome " << LoggedInUser.GetUsername() << " :)\n" << endl;
panel2:
	cout << "\nUser Panel\n" << endl;
	cout << "\t1. Register Article        2. See List of Articles        3. Sign Out" << endl;
	int cmd;
	cin >> cmd;
	switch (cmd) {
	case 1: {

		RegisterArticle();
		goto panel2;

	}
	case 2:
		ShowAllArticles();
		goto panel2;
	case 3: {
		LoggedInUser.SetPassword("");
		LoggedInUser.SetUserId(-1);
		LoggedInUser.SetUsername("");
		goto firstpage;
	}

	default:
		goto panel;
	}

}