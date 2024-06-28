#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

#define MAX 217 // max number of rows

// ! Classes

class Password
{
    int max;
    string *password;

public:
    Password()
    {
        max = MAX;
        password = new string[max];
    }
    Password(int m)
    {
        max = m;
        password = new string[max];
    }

    void setPasswordrows(int m)
    {
        max = m;
        password = new string[max];
    }

    void set_password(int index)
    {
        string temp;
        int count = 0;

        cout << "\nCreating Password..." << endl;

        cout << "Conditions: atleast 6 characters, 1 Digit, 1 Uppercase, 1 Lowercase, 1 Symbol." << endl
             << endl;
        cout << "Enter Password : ";

        password[index] = hidePassword(password[index]);

        // cout << "\npassword: " << password[index] << endl;

        while ((!check_Password_Conditions(password[index])) && (password[index] != "~"))
        {
            cout << "\nPlease Try Again" << endl;
            cout << "Press ~ to Restart\n";
            cout << "Conditions: atleast 6 characters, 1 Digit, 1 Uppercase, 1 Lowercase, 1 Symbol." << endl
                 << endl;
            cout << "\nEnter Password : ";
            password[index] = "";
            password[index] = hidePassword(password[index]);
            cout << endl;
        }

        cout << "\nReEnter Password : ";
        temp = hidePassword(temp);

        while ((temp != password[index]) && (password[index] != "~") && (temp != "~"))
        {
            cout << "\nWrong Password!\nTry again\n";
            cout << "Press ~ to exit\n";
            cout << "\nReEnter Password : ";
            temp = "";
            temp = hidePassword(temp);
        }
        if (temp == "~")
        {
            password[index] = "";
            temp = "";
        }

        if ((password[index] == "~") || (temp == "~"))
        {
            cout << "\nPassword Not Created!" << endl;
        }
        cout << "\n\nPassword Successfully Created!\n";
        // cout << "\n\nYour Password is : " << password[index] << endl;
    }

    bool check_Password_Conditions(string str)
    {
        int digit = 0, Upper_case = 0, Lower_case = 0, symbol = 0, i;

        // Checks conditions for validation of password
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                digit++;
            }

            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                Upper_case++;
            }

            else if (str[i] >= 'a' && str[i] <= 'z')
            {
                Lower_case++;
            }
            else
                symbol++;
        }

        // Prints invalid conditions
        if (Upper_case == 0)
            cout << "\nPassword contains No Upper Case Characters!\n";

        if (Lower_case == 0)
            cout << "\nPassword contains No Lower Case Characters!\n";

        if (digit == 0)
            cout << "\nPassword contains No Digits!\n";

        if (symbol == 0)
            cout << "\nPassword contains No Symbols!\n";

        if (i < 6)
            cout << "\nPassword lenght is Less than 6!\n";

        if (Upper_case > 0 && Lower_case > 0 && digit > 0 && symbol > 0 && i >= 6)
            return true;

        else
            return false;
    }

    string hidePassword(string password)
    {
        char c;

        while ((c = getch()) != '\r')
        {
            if (c == '\b')
            { // handle backspace
                if (password.length() > 0)
                {
                    password.erase(password.length() - 1); // remove last character from string
                    cout << "\b \b";                       // move cursor back, overwrite with space, move cursor back again
                }
            }
            else
            {
                password += c;
                cout << "*"; // print '*' instead of actual character
            }
        }

        return password;
    }

    void display_Password(int index)
    {
        cout << "\nPassword : " << password[index] << endl;
    }

    int passwordExists(string str)
    {
        for (int i = 0; i < max; i++)
        {
            // cout << "\nPassword :" << password[i] << endl;
            if (str == password[i])
                return i;
        }
        return -1;
    }

    int getPassword_index(string str)
    {
        for (int i = 0; i < max; i++)
        {
            if (password[i] == str) // Finds password and displays
                return i;
        }
        return -1;
    }

    string get_password(int index)
    {
        return password[index];
    }
};

class Questions
{
    // int answer;
    char c;
    char answer;
    char question[50];
    char option1[50];
    char option2[50];

public:
    Questions()
    {
        // answer = 0;
    }
    void set_Q()
    {
        cout << "\nPress any key to continue...\n"; // This is done to prevent cin.ignore() skipping characters
        cin >> c;

        cout << "\n\nEnter Question : ";
        cin.ignore();
        // getline(cin, question);
        cin.get(question, 50);

        cout << "Option 1 : ";
        cin.ignore();
        // getline(cin, option1);
        cin.get(option1, 50);

        cout << "Option 2 : ";
        cin.ignore();
        cin.get(option2, 50);
        // getline(cin, option2);

        cout << "Enter Answer : ";
        cin >> answer;
    }
    void display_Q()
    {
        cout << "\n\n\t\t!*****************************************\n\n";
        cout << "\t\t!  Question : " << question << endl;
        cout << "\t\t!  Option1  : " << option1 << endl;
        cout << "\t\t!  Option2  : " << option2 << endl;
        cout << "\t\t!  Answer  : " << answer << endl;
        cout << "\n\t\t!*****************************************\n\n";
    }
    Questions get_Q()
    {
        return *this; // returns the Question
    }

    void display_Quiz_Qs()
    {
        // Displays question without answers
        cout << "\n\n\t\t!*****************************************\n\n";
        cout << "\t\t!  Question : " << question << endl;
        cout << "\t\t!  Option1  : " << option1 << endl;
        cout << "\t\t!  Option2  : " << option2 << endl;
        cout << "\n\t\t!*****************************************\n\n";
    }
    void display_Question_string()
    {
        cout << "\nQuestion : " << question << endl;
    }
    char get_answer()
    {
        return answer;
    }
};

class Topics
{
    Questions questions[5];
    int total_Q;
    char name[30];

public:
    static int count;
    Topics()
    {
        total_Q = 0;
        // questions = new Questions[5];
    }
    void Add_Q()
    {
        questions[total_Q++].set_Q(); // adding question to topic and increasing question count
    }
    void display_All_Qs()
    {
        cout << "\nTopic : " << name << endl;

        for (int i = 0; i < total_Q; i++)
        {
            cout << "\nQuestion " << i + 1 << " : ";
            questions[i].display_Q();
            // cout << "Q num : " << total_Q << endl;
        }
    }
    void remove_Q()
    {
        int Q;

        cout << "Enter the Question Number You want to Delete : ";
        cin >> Q;

        Q--;

        leftShift_Qs(Q); // Removing question by overwriting it by the question on it's right
    }
    void leftShift_Qs(int index)
    {
        for (int i = index; i < total_Q; i++)
        {
            questions[i] = questions[i + 1];
        }
        total_Q--;
    }
    Questions getRandomQuestion(int checker[][20], int size, int index)
    {
        srand(time(0));
        int i, counter = 0;
        int random = rand() % total_Q;

        // if (count > size)
        if (count >= size)
            count = 0;

        while (true)
        {
            // if (check_Question_Array(checker, random, size, index) || counter == 20)
            if (check_Question_Array(checker, random, total_Q, index) || counter == 20) // Tries to check for repeatition of the same question in a quiz 20 times
            {
                break;
            }

            random = rand() % total_Q;
            counter++;
        }

        checker[index][count++] = random;

        return questions[random];
    }
    bool check_Question_Array(int check[][20], int random, int size, int index)
    {
        for (int i = 0; i < size; i++)
        {
            // cout << random << " " << check[index][i] << endl;

            if (random == check[index][i])
                return false;
        }
        return true;
    }
    int get_TotalQs()
    {
        return total_Q;
    }
    Questions getQuestion()
    {
        if (count >= total_Q)
            count = 0;
        return questions[count++];
    }
    void set_T_Name()
    {
        cout << "Enter Topic Name : ";
        // cin.ignore();
        // getline(cin, name);
        cin.get(name, 30);
    }
    void display_T_Name()
    {
        cout << "Topic : " << name << "\n";
    }
    void delete_Question()
    {
        int Q;

        cout << "Enter Question Number you want to delete : ";
        cin >> Q;

        Q--;

        for (int i = 0; i < total_Q; i++)
        {
            if (i >= Q)
            {
                questions[i] = questions[i + 1]; // Deletes Question by overwriting it with the question on the right
            }
        }
        total_Q--;
    }
};
int Topics::count = 0;

class Course
{
    Topics topics[5];
    int total_T;
    char name[30];
    int course_id;

public:
    static int topic_count;
    Course()
    {
        total_T = 0;
        course_id = 0;
        // topics = new Topics[5];
    }
    void set_Course_Name(const char *c_name, int course_id)
    {
        int i;

        /*
                // strcpy(name, c_name);
                for (i = 0; c_name[i] != '\0'; i++)
                {
                }
                // name = new char[i + 1];
                for (int j = 0; j < i; j++)
                {
                    name[j] = c_name[j];
                }
        */

        for (i = 0; c_name[i] != '\0'; i++)
        {
            name[i] = c_name[i];
        }
        name[i] = '\0';
        cout << "\n\ncourse name : " << name << endl
             << "Course id : " << course_id << endl; // Sets course name and id

        this->course_id = course_id;
    }
    void ADD_T()
    {
        topics[total_T++].set_T_Name();
        // topics[total_T++].Add_Q();
    }
    void remove_T()
    {
        int T;

        cout << "Enter the Topic Number You want to Delete : ";
        cin >> T;

        T--;

        leftShift_Ts(T);
    }
    void leftShift_Ts(int index)
    {
        for (int i = index; i < total_T; i++)
        {
            topics[i] = topics[i + 1]; // Left shift topics to overwrite
        }
        total_T--;
    }
    void display_All_Topic_Qs()
    {
        for (int i = 0; i < total_T; i++)
        {
            topics[i].display_All_Qs();
            // cout << "topics : " << total_T << endl;
        }
        cout << "topics : " << total_T << endl;
    }
    void Add_Q_to_Topic()
    {
        int T, Num_of_Qs;

        display_Topics();

        cout << "Enter Topic Number : ";
        cin >> T;

        T--;

        cout << "Enter How Many Qs : ";
        cin >> Num_of_Qs;

        for (int i = 0; i < Num_of_Qs; i++)
        {
            topics[T].Add_Q(); // Adds new question(s) to specified topic
        }
    }
    void display_Topic_Qs()
    {
        int T, Num_of_Qs;

        display_Topics();

        cout << "Enter Topic Number : ";
        cin >> T;

        T--;

        topics[T].display_All_Qs(); // Display all the questions of a specified topic
    }
    void display_Topics()
    {
        for (int i = 0; i < total_T; i++)
        {
            cout << i + 1 << ". ";
            topics[i].display_T_Name(); // Display All Topics
        }
    }
    Questions get_Question()
    {
        int T;

        display_Topics();

        cout << "Enter Which Topic you want the Question from : ";
        cin >> T;

        T--;

        return topics[T].getQuestion(); // Get question using static count
    }
    Questions get_Random_Question(int checker[][20], int size)
    {
        int T;

        display_Topics();

        cout << "Enter Which Topic you want the Question from : ";
        cin >> T;

        T--;

        return topics[T].getRandomQuestion(checker, size, T); // Get random question from specified topic
    }
    Questions get_Random_Topics_Question(int checker[][20], int size, int topic_checker[])
    {
        int T, counter = 0;

        srand(time(0));

        if (size <= topic_count) // resets count to 0 if it exceeds size
            topic_count = 0;

        do
        {
            T = rand() % total_T;
            counter++;
        } while (check_Topic_repetition(topic_checker, size, T) && counter <= 20); // Checks for repition of topic 20 times or less

        topic_checker[topic_count++] = T;

        return topics[T].getRandomQuestion(checker, size, T); // Get random question from random topic
    }
    void Save(string filename)
    {
        fstream file(filename, ios::out | ios::binary);
        file.write((char *)this, sizeof(*this));
        file.close();
    }
    void Load1(string filename)
    {
        Course course;
        fstream file(filename, ios::in | ios::binary);
        (file.read((char *)&course, sizeof(course)));
        file.close();

        /*
                int x;
                cout << "1. View All Topics Questions \n"
                     << "2.View All Topics \n"
                     << "3.View All Questions from a Topic\n"
                     << "Enter : ";
                cin >> x;

                switch (x)
                {
                case 1:
                    course.display_All_Topic_Qs();
                    break;
                case 2:
                    course.display_Topics();
                    break;
                case 3:
                    course.display_Topic_Qs();
                    break;
                default:
                    cout << "Invalid Entry" << endl;
                }
        */
    }
    void Load(string filename)
    {
        // int x;
        // cout << "\n1. View All Topics Questions \n"
        //      << "2.View All Topics \n"
        //      << "3.View All Questions from a Topic\n"
        //      << "Enter : ";
        // cin >> x;

        fstream file(filename, ios::in | ios::binary);
        while (file.read((char *)this, sizeof(*this)))
        {
            display_All_Topic_Qs();
            /*
            switch (x)
            {
            case 1:
                display_All_Topic_Qs();
                break;
            case 2:
                display_Topics();
                break;
            case 3:
                display_Topic_Qs();
                break;
            default:
                cout << "Invalid Entry" << endl;
            }
            */
        }
        file.close();
    }
    int get_total_topics()
    {
        return total_T;
    }
    int get_course_id()
    {
        return course_id;
    }
    void remove_topic(string filename)
    {

        Load(filename);

        int T;

        display_Topics();

        cout << "Enter Which Topic you want to delete : ";
        cin >> T;

        T--;

        for (int i = 0; i < total_T; i++)
        {
            if (i >= T)
            {
                topics[i] = topics[i + 1]; // Removes topic by overwriting from the right
            }
        }
        total_T--;

        // cout << "jj\n\n\n";

        display_All_Topic_Qs();

        // Save(filename);
    }
    void remove_Question(string filename)
    {
        Load(filename);

        int T;

        display_Topics();

        cout << "Enter Which Topic you want to delete Question from : ";
        cin >> T;

        T--;

        topics[T].delete_Question(); // Deletes question from the topic

        // Save(filename);
    }
    bool check_Topic_repetition(int topic_checker[], int size, int T)
    {
        for (int i = 0; i < size; i++)
        {
            if (topic_checker[i] == T) // checks for repitition of Topics
                return true;
        }
        return false;
    }
};
int Course::topic_count = 0;

class Student_Data
{
    string *student_name;
    string *student_roll;
    string **student_registered_courses;
    Password P;
    string *FileData;

public:
    Student_Data()
    {
        student_name = new string[MAX];
        student_roll = new string[MAX];

        student_registered_courses = new string *[MAX];
        for (int i = 0; i < MAX; i++)
            student_registered_courses[i] = new string[11];

        FileData = new string[MAX];
        ReadFile(); // Reads all Student Data and stores it
        sepStudentNames();
    }

    bool ReadFile()
    {
        ifstream file("Course Registration Data - Sheet1.csv", ios::in);
        if (!getline(file, FileData[0]))
            return 0;

        for (int i = 0; i < MAX; i++)
            getline(file, FileData[i]); // stores lines in the form of rows in FileData

        file.close();
        return 1;
    }

    string *colSeparate(string *&fileData, int colNum, int maxRows, char delim = ',')
    {
        string temp;
        string *res = new string[maxRows];
        for (int i = 0; i < maxRows; i++)
        {
            stringstream lineStream(fileData[i]);

            // Skip over preceding columns
            for (int j = 0; j < colNum; j++)
                getline(lineStream, temp, ',');

            // Get value of desired column
            getline(lineStream, res[i], delim);
        }
        return res;
    }

    void separateStudentName(string *&fileData)
    {
        student_name = colSeparate(fileData, 2, MAX);

        // for (int i = 0; i < MAX; i++)
        // {
        //     cout << student_name[i] << endl;
        // }
    }

    void separateStudentRollNumber(string *&fileData)
    {
        student_roll = colSeparate(fileData, 1, MAX);

        // for (int i = 0; i < MAX; i++)
        // {
        //     cout << student_roll[i] << endl;
        // }
    }

    void separateStudentCourses(string *&fileData)
    {
        // setting size of courses
        student_registered_courses[0] = colSeparate(fileData, 3, MAX);
        student_registered_courses[1] = colSeparate(fileData, 4, MAX);
        student_registered_courses[2] = colSeparate(fileData, 5, MAX);
        student_registered_courses[3] = colSeparate(fileData, 6, MAX);
        student_registered_courses[4] = colSeparate(fileData, 7, MAX);
        student_registered_courses[5] = colSeparate(fileData, 8, MAX);
        student_registered_courses[6] = colSeparate(fileData, 9, MAX);
        student_registered_courses[7] = colSeparate(fileData, 10, MAX);
        student_registered_courses[8] = colSeparate(fileData, 11, MAX);
        student_registered_courses[9] = colSeparate(fileData, 12, MAX);
        student_registered_courses[10] = colSeparate(fileData, 13, MAX);

        string transpose[MAX][11];

        // taking transpose of student_registered_courses to store the data in a formated form
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < 11; j++)
                transpose[i][j] = student_registered_courses[j][i];
        }

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                student_registered_courses[i][j] = transpose[i][j];
            }
        }
    }

    void display_Student_Names()
    {
        for (int i = 0; i < MAX; i++)
        {
            cout << student_name[i] << endl;
        }
    }

    void display_Student_RollNum()
    {
        for (int i = 0; i < MAX; i++)
        {
            cout << student_roll[i] << endl;
        }
    }

    void display_Student_Courses()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                cout << student_registered_courses[i][j] << "  ";
            }
            cout << endl;
        }
    }

    int findRollNumbers(string id)
    {
        separateStudentRollNumber(FileData); // * NEW LINE

        for (int i = 0; i < MAX; i++)
        {
            // cout << id << " " << student_roll[i] << endl;
            if (id == student_roll[i])
                return i;
        }
        return -1;
    }

    bool RollNumberExists(string id)
    {
        for (int i = 0; i < MAX; i++)
        {

            // cout << "Roll : " << id << " " << student_roll[i] << endl;
            if (id == student_roll[i])
                return true;
        }
        return false;
    }

    void display_Student(int index)
    {
        cout << "\nRoll Number : " << student_roll[index] << endl
             << "\nStudent Name : " << student_name[index] << endl;

        cout << "\nCourse registered : \n";
        for (int i = 0; i < 11; i++)
        {
            if (student_registered_courses[index][i] == "1")
                cout << student_registered_courses[0][i] << endl;
        }
    }

    void setPassword_student(int index)
    {
        P.set_password(index);
    }

    void displayStudent_Password(int index)
    {
        P.display_Password(index);
    }

    int Student_Password_Index(string str)
    {
        return P.passwordExists(str);
    }

    void sepStudentNames()
    {
        student_name = colSeparate(FileData, 2, MAX);
    }

    void display_student_name(int index)
    {
        cout << student_name[index];
    }

    int *get_registered_courses(int index)
    {
        int count = 0;
        int *reg_course = new int[11];

        for (int i = 0; i < 11; i++)
        {
            reg_course[i] = -1;
            if (student_registered_courses[index][i] == "1")
            {
                reg_course[count++] = i;
            }
        }

        return reg_course; // returns column of students registered in a course
    }

    string get_Name(int index)
    {
        return student_name[index];
    }

    string get_Password(int index)
    {
        return P.get_password(index);
    }

    string get_RollNumber(int index)
    {
        return student_roll[index];
    }

    string **get_Courses(int index)
    {
        separateStudentCourses(FileData);
        return student_registered_courses;
    }
};

class Quiz
{
    Questions q[10];
    int n;
    int markSheet[MAX][11];
    char answers[11];
    int attendance[MAX];
    int graph[11];
    int course_id;
    char Date_time[100];

public:
    Quiz()
    {
        n = 0;
        course_id = 0;

        for (int i = 0; i < MAX; i++)
        {
            attendance[i] = 0;
            for (int j = 0; j < 11; j++)
            {
                markSheet[i][j] = 0;
            }
        }
        for (int i = 0; i < 11; i++)
        {
            graph[i] = 0;
        }
    }
    void generate_Quiz(Course c)
    {
        int choice = -1;
        int checker[20][20];
        int topic_checker[20];

        cout << "\nEnter Number of Questions in Quiz : ";
        cin >> n;

        if (cin.fail())
        {
            cin.clear();                                         // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears all contents of the input till '\n' or max characters
            n = 0;
            throw "\nERROR : Invalid Entry";
        }

        if (n > 0)
        {
            do
            {
                cout << "\n1. Random Question" << endl
                     << "2. Sorted Question" << endl
                     << "3. Completetly Random Quiz" << endl;
                cin >> choice;

                if (cin.fail())
                {
                    cin.clear();                                         // Clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears all contents of the input till '\n' or max characters
                    choice = 3;
                    throw "\nERROR : Invalid Entry";
                }

                course_id = c.get_course_id();

            } while (choice != 3 && choice != 1 && choice != 2);

            do
            {
                switch (choice)
                {
                case 1:

                    for (int i = 0; i < 20; i++)
                        for (int j = 0; j < 20; j++)
                            checker[i][j] = -1;

                    for (int i = 0; i < n; i++)
                    {
                        q[i] = c.get_Random_Question(checker, n);
                    }
                    break;

                case 2:
                    for (int i = 0; i < n; i++)
                    {
                        q[i] = c.get_Question();
                    }
                    break;

                case 3:
                {
                    for (int i = 0; i < 20; i++)
                    {
                        topic_checker[i] = -1;
                        for (int j = 0; j < 20; j++)
                        {
                            checker[i][j] = -1;
                        }
                    }

                    for (int i = 0; i < n; i++)
                    {
                        q[i] = c.get_Random_Topics_Question(checker, n, topic_checker);
                    }
                    break;
                }

                default:
                    cout << "ERROR: InValid Input" << endl;
                    // cin.clear();
                    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    // cout << "Enter 1-3 : ";
                    // cin >> choice;
                    break;
                }

            } while (choice != 1 && choice != 2 && choice != 3);

            cout << "Set Date and Time in this Format [ %Y-%m-%d %H:%M:%S ] : ";
            cin.ignore();
            cin.get(Date_time, 100);

            save();
        }

        else
        {
            cout << "\nNo Questions Added" << endl;
        }
    }
    void save()
    {
        ofstream f_write("Quiz.bin", ios::out | ios::binary);
        f_write.write((char *)this, sizeof(*this));
        f_write.close();
    }
    void read()
    {
        ifstream f_read("Quiz.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        f_read.read((char *)this, sizeof(*this));
        f_read.close();
        display();
    }
    void display()
    {
        cout << "\nDate and Time : " << Date_time << endl;

        for (int i = 0; i < n; i++)
        {
            cout << "\n\nQuestion " << i + 1 << " : ";
            q[i].display_Quiz_Qs();
        }
    }
    void attempt_Quiz(int index, int *course_ID)
    {
        cout << "\nQUIZ \n***********************************\n";
        // read();
        load();

        //  Check for courses
        if (checkCourse(course_ID))
        {

            //  Attempted already?
            if (attendance[index] == 0)
            {
                // Check Valid Date
                if (checkDate())
                {
                    display();

                    cout << "Enter Your Answers \n***********************************\n";

                    for (int i = 0; i < n; i++)
                    {
                        cout << "\nEnter Answer " << i + 1 << " : ";
                        cin >> answers[i];
                    }

                    for (int i = 0; i < n; i++)
                    {
                        cout << "\nAnswer " << i + 1 << " : " << answers[i];
                    }

                    cout << endl
                         << endl;

                    Mark_Answers(index);
                    Mark_Attendance(index);
                    set_Graph(index);
                }
            }
            else
                cout << "\nYou have already attmepted the Quiz!" << endl;
        }
        else
            cout << "\n!You are Not Registered in this Course!\n";

        cout << "\n***********************************\n";
    }
    void Mark_Answers(int index)
    {
        for (int i = 0; i < n; i++)
        {
            if (answers[i] == q[i].get_answer())
                markSheet[index][i] = 1;
            else
                markSheet[index][i] = 0;
        }
        save();
    }
    void view_Mark(int index)
    {
        cout << "\nMarks \n***********************************\n\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Question " << i + 1 << " : " << markSheet[index][i] << endl;
        }
        cout << "\n***********************************\n";
    }
    void load()
    {
        ifstream f_read("Quiz.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        f_read.read((char *)this, sizeof(*this));
        f_read.close();
    }
    void view_MarkSheet()
    {
        load();
        Student_Data s;

        cout << "\nMarkSheet \n***********************************\n\nQuestion Number :    ";

        for (int i = 0; i < n; i++)
        {
            cout << "Q" << i + 1 << " ";
        }
        cout << endl
             << endl;

        for (int i = 1; i < MAX; i++)
        {
            s.display_student_name(i);
            cout << "'s Marks : ";
            for (int j = 0; j < n; j++)
            {
                cout << markSheet[i][j] << " ";
            }
            cout << endl
                 << endl;
        }

        cout << "\n***********************************\n\n";
    }
    bool checkDate()
    {
        time_t current_time = time(nullptr);
        char time_str[100];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
        cout << "\nCurrent time: " << time_str << '\n';

        // Convert user input to time_t
        time_t input_time = string_to_time(Date_time);
        if (input_time == -1)
        {
            cout << "Invalid date format\n";
            return 1;
        }

        // Compare user input to current time
        double diff = difftime(input_time, current_time);
        if (diff > 0)
        {
            cout << "\nTimes Remains: " << diff << " seconds\n\n";
            return true;
        }
        else
        {
            cout << "\nDue Time : " << Date_time << endl;
            cout << "\nTimes UP\n\n";
            return false;
        }
    }
    time_t string_to_time(const string &str)
    {
        struct tm tm = {};
        if (str.size() != 19)
        {
            return -1;
        }

        // Converting portion of string into date and time components
        tm.tm_year = stoi(str.substr(0, 4)) - 1900;
        tm.tm_mon = stoi(str.substr(5, 2)) - 1;
        tm.tm_mday = stoi(str.substr(8, 2));
        tm.tm_hour = stoi(str.substr(11, 2));
        tm.tm_min = stoi(str.substr(14, 2));
        tm.tm_sec = stoi(str.substr(17, 2));
        return mktime(&tm);
    }
    void Mark_Attendance(int index)
    {
        attendance[index] = 1;

        save();
    }
    void Generate_Key()
    {
        load();

        cout << "\nAnswer Key\n***********************************\n\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Answer " << i + 1 << " : " << q[i].get_answer() << endl;
        }

        cout << "\n***********************************\n\n";
    }
    void view_attendance()
    {
        load();
        Student_Data s;

        cout << "\nAttendance\n***********************************\n\n";

        for (int i = 1; i < MAX; i++)
        {
            s.display_student_name(i);
            cout << " : ";
            cout << attendance[i] << endl
                 << endl;
        }

        cout << "\n***********************************\n\n";
    }
    void set_Graph(int index)
    {
        load();
        // for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((markSheet[index][j]) == 1)
                {
                    graph[j]++; // increments bar graph of a quesiton
                }
            }
        }
        save();
    }
    void view_Graph()
    {
        load();

        cout << "\nQuiz Analytics \n***********************************";

        for (int i = 0; i < n; i++)
        {
            cout << "\n\nQuestion " << i + 1 << " : ";
            for (int j = 0; j < graph[i]; j++)
            {
                cout << "-";
            }
        }
        cout << "\n\n***********************************\n\n";
    }
    bool checkCourse(int *courses)
    {
        for (int i = 0; i < 11; i++)
        {
            if (courses[i] == course_id) // Checks to see if registered in the course
                return true;
        }
        return false;
    }
};

class Student_Login
{
    char ID[50];
    char password[50];
    char name[50];
    char courses[11][10];
    int index;
    int rows;
    Student_Data s;

public:
    Student_Login()
    {
        rows = 0;
        index = -1;
    }
    int Student_Log_In()
    {
        int choice = 0;
        Student_Data s;
        Student_read();
        s.ReadFile();
        index = -1;
        string Password;

        cout << "\nLogin in For Students \n";
        cout << "\n*****************************************\n\n";

        cout << "Press ~ to Exit\n\n";

        cout << "Enter your NU ID : ";
        cin >> ID;
        cout << "Enter your password : ";
        Password = HidePassword(Password);

        if (ID == "~" || password == "~")
        {
            cout << "\nLog out Failed.\n";
            return -1;
        }

        index = Check_student_data(ID, Password);

        while ((index == -1))
        {
            cout << "\nInvalid password or ID.\nTry Again.\n\nEnter : ";
            cout << "Enter your NU ID : ";
            cin >> ID;

            cout << "Enter Password : ";
            Password = "";
            Password = HidePassword(Password);

            if (ID == "~" || Password == "~")
            {
                cout << "\nLog in Failed.\n";
                return -1;
            }
            index = Check_student_data(ID, Password);
        }

        cout << "\n\nLogin Successful!" << endl;

        display();

        cout << "\n*****************************************\n\n";

        return index;
    }
    int Student_Sign_In()
    {
        Student_Data s;

        s.ReadFile();

        clear_data();

        string Id, Password, temp_name;
        string *temp_courses;

        int Index;

        cout << "\nPress ~ to Exit\n\n";

        cout << "Enter your NU ID : ";
        cin >> Id;

        if (Id == "~")
        {
            cout << "\nSign in Exiting.\n";
            return -1;
        }

        index = s.findRollNumbers(Id);

        while (index == -1)
        {
            cout << "\nRoll Number Not Found.\nPLease try Again.\nEnter your NU ID : ";
            cin >> Id;

            index = s.findRollNumbers(Id);
        }

        s.setPassword_student(index);

        cout << "\nSigned In Successful!" << endl;

        temp_name = s.get_Name(index);
        Password = s.get_Password(index);
        Id = s.get_RollNumber(index);

        string **course = s.get_Courses(index);

        copyToChar(Id, Password, temp_name, course, index);

        Student_save();

        Student_find(Id, Password);

        display();

        cout << "\n*****************************************\n\n";

        return index;
    }
    void copyToChar(string id, string Password, string temp_name, string **temp_courses, int index)
    {
        int i, j;

        // Copies everything into a char array
        for (i = 0; id[i] != '\0'; i++)
        {
            ID[i] = id[i];
        }
        ID[i] = '\0';

        for (i = 0; Password[i] != '\0'; i++)
        {
            password[i] = Password[i];
        }
        password[i] = '\0';

        for (i = 0; temp_name[i] != '\0'; i++)
        {
            name[i] = temp_name[i];
        }
        name[i] = '\0';

        for (int i = 0; i < 11; i++)
        {
            if (temp_courses[index][i] == "1")
            {
                for (j = 0; temp_courses[0][i][j] != '\0'; j++)
                {
                    courses[rows][j] = temp_courses[0][i][j];
                }
                courses[rows][j] = '\0';
                rows++;
            }
        }
    }
    void Student_save()
    {
        ofstream f_write("Student.bin", ios::out | ios::app | ios::binary);
        f_write.write((char *)this, sizeof(*this));
        f_write.close();
    }
    void Student_read()
    {
        ifstream f_read("Student.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        while (f_read.read((char *)this, sizeof(*this)))
        {
        }

        f_read.close();
    }
    void Student_find(string temp_ID, string temp_password)
    {
        ifstream f_read("Student.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        while (f_read.read((char *)this, sizeof(*this)))
        {
            if (ID == temp_ID && password == temp_password)
            {
                display();
            }
        }

        f_read.close();
    }
    void display()
    {
        cout << "\n\nUser Details\n---------------------------------\n";

        cout << "\nRoll Number : " << ID << endl;
        cout << "\nStudent Name : " << name << endl;
        cout << "\nPassword : " << password << endl;

        cout << "\nCourses : \n";
        for (int i = 0; i < rows; i++)
        {
            cout << courses[i] << "  ";
        }

        cout << "\n\n---------------------------------\n";
    }
    string HidePassword(string password)
    {
        char c;

        while ((c = getch()) != '\r')
        {
            if (c == '\b')
            { // handle backspace
                if (password.length() > 0)
                {
                    password.erase(password.length() - 1); // remove last character from password string
                    cout << "\b \b";                       // move cursor back, overwrite with space, move cursor back again
                }
            }
            else
            {
                password += c;
                cout << "*"; // print '*' instead of actual character
            }
        }

        return password;
    }
    int Check_student_data(string id, string Password)
    {
        ifstream f_read("Student.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return -1;
        }
        while (f_read.read((char *)this, sizeof(*this)))
        {
            if (id == ID && password == Password) // Finds student index in Student database
            {
                return index;
            }
        }

        f_read.close();

        return -1;
    }
    void clear_data()
    {
        for (int i = 0; i < 50; i++)
        {
            ID[i] = '\0';
            password[i] = '\0';
            name[i] = '\0';
        }

        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 10; j++)
                courses[i][j] = '\0';

        rows = 0;
        index = -1;
    }
    int New_Password(int index)
    {

        delete_password();
        Student_Sign_In();

        return 0;
    }
    int delete_password()
    {
        char temp_ID[30], temp_password[30];
        string p;
        int i;

        // Deletes passwords and sets a new one

        cout << "\nLogin in For Students \n";
        cout << "\n*****************************************\n\n";

        cout << "Press ~ to Exit\n\n";

        cout << "Enter your old NU ID : ";
        cin >> temp_ID;
        cout << "Enter your old password : ";
        p = HidePassword(p);

        for (i = 0; p[i] != '\0'; i++)
        {
            temp_password[i] = p[i];
        }
        temp_password[i] = '\0';

        // if (temp_ID == "~" || temp_password == "~")
        if (strcmp(temp_ID, "~") == 0 || strcmp(temp_password, "~") == 0)
        {
            cout << "\nLog out Failed.\n";
            return 0;
        }

        i = 0;

        ofstream f_write;
        f_write.open("temp.bin", ios::in | ios::app | ios::binary);

        ifstream f_read("Student.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return 0;
        }

        while (f_read.read((char *)this, sizeof(*this)))
        {
            cout << ID << " " << temp_ID << " - - " << password << " " << temp_password << endl;
            // if (ID == temp_ID && password == temp_password)
            if (strcmp(ID, temp_ID) == 0 && strcmp(password, temp_password) == 0)
            {
                cout << "\nDELETING PASSWORD " << endl;
                display();
                i++;
            }
            else
            {
                f_write.write((char *)this, sizeof(*this));
            }
        }

        f_read.close();
        f_write.close();
        remove("Student.bin");
        rename("temp.bin", "Student.bin");
        if (i == 0)
        {
            cout << "\nRecord not found\n";
        }
        return 0;
    }
};

class Student
{
    Student_Data s;
    string *fileData;
    string ID;
    string password;
    int index;
    Quiz Q;
    Student_Login sl;

public:
    Student()
    {
        fileData = new string[MAX];
        getStudentData();
        index = 0;
    }
    bool readFile()
    {
        ifstream file("Course Registration Data - Sheet1.csv", ios::in);
        if (!getline(file, fileData[0]))
            return 0;

        for (int i = 0; i < MAX; i++)
            getline(file, fileData[i]);

        file.close();
        return 1;
    }
    void getStudentCourses()
    {
        s.separateStudentCourses(fileData);
        s.display_Student_Courses();
    }
    bool student_SignIn()
    {
        cout << "\nSign in";
        cout << "\n*****************************************\n\n";
        index = sl.Student_Sign_In();

        if (index == -1) // if Signed in successfully or not
            return false;
        return true;
    }
    void getStudentData()
    {
        readFile();
        s.separateStudentCourses(fileData);
        s.separateStudentName(fileData);
        s.separateStudentRollNumber(fileData);
    }
    void display_Student_Password()
    {
        // passWord.display_Password(index);
        s.displayStudent_Password(index);
    }
    void FindStudent()
    {
        cout << "Enter your NU ID : ";
        cin >> ID;

        index = s.findRollNumbers(ID);
    }
    bool student_LogIn()
    {
        index = sl.Student_Log_In();

        if (index == -1) // if Logged in successfully or not
            return false;
        return true;
    }
    string HidePassword(string password)
    {
        char c;

        while ((c = getch()) != '\r')
        {
            if (c == '\b')
            { // handle backspace
                if (password.length() > 0)
                {
                    password.erase(password.length() - 1); // remove last character from password string
                    cout << "\b \b";                       // move cursor back, overwrite with space, move cursor back again
                }
            }
            else
            {
                password += c;
                cout << "*"; // print '*' instead of actual character
            }
        }

        return password;
    }
    void display_student_data()
    {
        s.display_Student(index);
    }
    void attempt_Quiz()
    {
        int *courses = new int[11]; // initialize courses with 11 number of topics
        courses = s.get_registered_courses(index);

        Q.attempt_Quiz(index, courses);
        // set_graph();
    }
    void View_Marks()
    {

        Q.view_Mark(index);
    }
    void display_Student_Name()
    {
        // s.sepStudentNames();

        // s.display_student_name(1);
    }
    void mark_attendance()
    {
        Q.Mark_Attendance(index); // Mark attendance of student of index
    }
    void set_graph()
    {
        Q.set_Graph(index); // Mark graph of student of index
    }
    void Student_change_password()
    {
        cout << "index : " << index << endl;
        // s.setPassword_student(index);
        sl.New_Password(index); // Change password of student of index
    }
};

class Teacher_Login
{
    char name[30];
    char password[30];
    int index;
    char teacher_Names[11][30];

public:
    Teacher_Login()
    {
        // teacher_Names[0] = "Adil Majeed";
        // teacher_Names[1] = "Jerome";
        // teacher_Names[2] = "Tyrone";
        // teacher_Names[3] = "Lebrone";
        // teacher_Names[4] = "James Bond";
        // teacher_Names[5] = "Kevin Hart";
        // teacher_Names[6] = "Michael Jordan";
        // teacher_Names[7] = "Ayesha Kamran";
        // teacher_Names[8] = "Saira Qamar";
        // teacher_Names[9] = "Black person";
        // teacher_Names[10] = "Monkey";

        index = -1;
    }
    bool teacher_Sign_In()
    {

        cout << "\nTeacher Sign In\n*****************************************\n";

        // cout << "Press p to continue..." << endl;
        // cin.get();

        cout << "\nEnter ~ if you want to Exit";
        cout << "\n\nEnter Teacher Name : ";
        // cin.ignore();
        cin.get(name, 30);

        if (strcmp(name, "~") == 0)
        {
            cout << "Sign In Failed" << endl;
            return false;
        }

        for (int i = 0; i < 11; i++)
        {
            if (name == teacher_Names[i])
                index = i;
        }

        cout << "\nEnter Teacher Password : ";
        // cin.ignore();
        // cin.get(password, 30);
        string p = "";
        password[0] = '\0';
        p = HidePassword(password);
        int i;
        for (i = 0; p[i] != '\0'; i++)
        {
            password[i] = p[i];
        }
        password[i] = '\0';

        if (strcmp(password, "~") == 0)
        {
            cout << "Sign In Failed" << endl;
            return false;
        }

        Teacher_save();

        cout << "\n\nSign In Successful" << endl;

        cout << "\nUser Details\n---------------------------------\n\n";
        cout << "Teacher Name : " << name << endl;
        cout << "Teacher Password : " << password << endl;
        cout << "\n---------------------------------\n";

        cout << "\n*****************************************\n";
        return true;
    }
    bool teacher_Log_In()
    {
        cout << "\nTeacher Log In\n*****************************************\n";

        char temp_name[30];
        int choice = 0;
        string Password;

        // cin.ignore();
        // cout << "\nPress p to continue...";
        // cin.get();

        cout << "\nEnter ~ if you want to Exit";

        cout << "\n\nEnter Teacher Name : ";
        // cin.ignore();
        cin.get(temp_name, 30);

        if (strcmp(temp_name, "~") == 0)
        {
            cout << "\nLog In Failed" << endl;
            return false;
        }

        cout << "Enter Teacher Password : ";
        Password = HidePassword(Password);

        if ((Password == "~"))
        {
            cout << "\nLog In Failed" << endl;
            return false;
        }

        if ((Password == "") && (strcmp(temp_name, "") == 0))
        {
            cout << "\nLog In Failed" << endl;
            return false;
        }

        while (!check_LogIn(temp_name, Password))
        {
            cout << "\nInvalid password or Name.\nTry Again.\n";

            cout << "\nEnter your Name : ";
            cin.ignore();
            cin.get(temp_name, 30);

            cout << "Enter your password : ";
            Password = "";
            Password = HidePassword(Password);

            // if (temp_name == "~" || (Password == "~"))
            if (strcmp(temp_name, "~") == 0 || (Password == "~"))
            {
                cout << "\nLog in Failed.\n";
                return false;
            }
        }

        cout << "\nLogin Successful!" << endl;

        cout << "\nUser Details\n---------------------------------\n\n";
        cout << "Teacher Name : " << temp_name << endl;
        cout << "Teacher Password : " << Password << endl;
        cout << "\n---------------------------------\n";

        cout << "\n*****************************************\n";

        return true;
    }
    void Teacher_save()
    {
        ofstream f_write("Teacher.bin", ios::out | ios::app | ios::binary);
        f_write.write((char *)this, sizeof(*this));
        f_write.close();
    }
    void Teacher_read()
    {
        ifstream f_read("Teacher.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        while (f_read.read((char *)this, sizeof(*this)))
        {
        }
        f_read.close();
    }
    bool check_LogIn(char temp_name[30], string temp_password)
    {
        ifstream f_read("Teacher.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return false;
        }
        while (f_read.read((char *)this, sizeof(*this)))
        {
            // if (temp_name == name && temp_password == password)
            if ((strcmp(temp_name, name) == 0) && ((temp_password == password)))
            {
                return true;
            }
        }
        f_read.close();
        return false;
    }
    void display()
    {
        cout << "Teacher Name : " << name << endl;
        cout << "Teacher Password : " << password << endl;
    }
    string HidePassword(string password)
    {
        char c;

        while ((c = getch()) != '\r')
        {
            if (c == '\b')
            { // handle backspace
                if (password.length() > 0)
                {
                    // ? Method 1 :
                    password.erase(password.length() - 1); // remove last character from password string

                    // ? Method 2 :
                    //// if (!password.empty())
                    // {
                    //     password = password.substr(0, password.length() - 1);
                    // }

                    cout << "\b \b"; // move cursor back, overwrite with space, move cursor back again
                }
            }
            else
            {
                password += c;
                cout << "*"; // print '*' instead of actual character
            }
        }

        return password;
    }
    void set_NewPassword()
    {
        deletePassword(); // delete old password

        // set new password

        cout << "Press p to continue..." << endl;
        cin.get();

        cout << "\nEnter ~ if you want to Exit";
        cout << "\nEnter New Teacher Name : ";
        // cin.ignore();
        cin.get(name, 30);

        if (strcmp(name, "~") == 0)
        {
            cout << "Sign In Failed" << endl;
            return;
        }

        for (int i = 0; i < 11; i++)
        {
            if (name == teacher_Names[i])
                index = i;
        }

        cout << "\nEnter New Teacher Password : ";
        // cin.ignore();
        // cin.get(password, 30);
        string p = "";
        password[0] = '\0';
        p = HidePassword(password);
        int i;
        for (i = 0; p[i] != '\0'; i++)
        {
            password[i] = p[i];
        }
        password[i] = '\0';

        if (strcmp(password, "~") == 0)
        {
            cout << "Sign In Failed" << endl;
            return;
        }

        Teacher_save();

        cout << "\n*****************************************\n";
    }
    void deletePassword()
    {
        cout << "\nTeacher Password Change\n*****************************************\n";

        char temp_name[30], temp_password[30];
        // cout << "Press p to continue..." << endl;
        // cin.get();

        cout << "\nEnter ~ if you want to Exit";
        cout << "\nReEnter old Teacher Name : ";
        cin.ignore();
        cin.get(temp_name, 30);

        if (strcmp(temp_name, "~") == 0)
        {
            cout << "Sign In Failed" << endl;
            return;
        }

        for (int i = 0; i < 11; i++)
        {
            if (temp_name == teacher_Names[i])
                index = i;
        }

        cout << "\nEnter old Teacher Password : ";
        // cin.ignore();
        // cin.get(password, 30);
        string p = "";
        temp_password[0] = '\0';
        p = HidePassword(temp_password);
        int i;
        for (i = 0; p[i] != '\0'; i++)
        {
            temp_password[i] = p[i];
        }
        temp_password[i] = '\0';

        if (strcmp(temp_password, "~") == 0)
        {
            cout << "Sign In Failed" << endl;
            return;
        }

        int count = 0;
        // p = "";

        ofstream f_write;
        f_write.open("temp.bin", ios::in | ios::app | ios::binary);

        ifstream f_read("Teacher.bin", ios::in | ios::binary);

        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        while (f_read.read((char *)this, sizeof(*this)))
        {
            // if (temp_password == password && temp_name == name)

            if (strcmp(temp_password, password) == 0 && strcmp(temp_name, name) == 0)
            {
                cout << "\n\nPassword Changed!\n"
                     << endl;
                count++;
                // p = password;
            }
            else
            {
                f_write.write((char *)this, sizeof(*this));
            }
        }

        f_read.close();
        f_write.close();
        remove("Teacher.bin");
        rename("temp.bin", "Teacher.bin");
        if (count == 0)
        {
            cout << "\nRecord not found\n";
        }
    }
};

class Teacher
{
    string name;
    Password password;
    Course courses[11];
    int total_C;
    int choice;
    Quiz Q;
    int *topic_chosen;
    string filename;
    string teacher_Names[11];
    string teacher_Passwords[11];
    int index;
    Teacher_Login t;

public:
    Teacher() : total_C(0)
    {
        name = "";
        teacher_Names[0] = "Adil Majeed";
        teacher_Names[1] = "Jerome";
        teacher_Names[2] = "Tyrone";
        teacher_Names[3] = "Lebrone";
        teacher_Names[4] = "James Bond";
        teacher_Names[5] = "Kevin Hart";
        teacher_Names[6] = "Michael Jordan";
        teacher_Names[7] = "Ayesha Kamran";
        teacher_Names[8] = "Saira Qamar";
        teacher_Names[9] = "Black person";
        teacher_Names[10] = "Monkey";

        teacher_Passwords[0] = "Adil Majeed";
        teacher_Passwords[1] = "Jerome";
        teacher_Passwords[2] = "Tyrone";
        teacher_Passwords[3] = "Lebrone";
        teacher_Passwords[4] = "James Bond";
        teacher_Passwords[5] = "Kevin Hart";
        teacher_Passwords[6] = "Michael Jordan";
        teacher_Passwords[7] = "Ayesha Kamran";
        teacher_Passwords[8] = "Saira Qamar";
        teacher_Passwords[9] = "Black person";
        teacher_Passwords[10] = "Monkey";

        password.setPasswordrows(11);

        index = -1;
    }
    void set_Name(string name)
    {
        this->name = name;
    }
    bool choose_course()
    {
        cout << "\nCourses\n***********************************\n\n";
        cout << "1. CS 101 " << endl
             << "2. CS 201 " << endl
             << "3. CS 102 " << endl
             << "4. CS 301 " << endl
             << "5. CS 302 " << endl
             << "6. SE 301 " << endl
             << "7. CS 501 " << endl
             << "8. CS 407 " << endl
             << "9. CS 307 " << endl
             << "10. CS 601 " << endl
             << "11. CS 409 " << endl
             << "0. Exit" << endl
             << "Enter Course : ";
        cin >> choice;
        choice--;

        switch (choice)
        {
        case 0:
            courses[choice].set_Course_Name("CS 101", 0);
            filename = "CS 101.bin";

            break;
        case 1:
            courses[choice].set_Course_Name("CS 201", 1);
            filename = "CS 201.bin";
            break;
        case 2:
            courses[choice].set_Course_Name("CS 102", 2);

            filename = "CS 102.bin";
            break;
        case 3:
            // courses[choice] = "CS 301";
            courses[choice].set_Course_Name("CS 301", 3);

            filename = "CS 301.bin";
            break;
        case 4:
            // courses[choice] = "CS 302";
            courses[choice].set_Course_Name("CS 302", 4);

            filename = "CS 302.bin";
            break;
        case 5:
            // courses[choice] = "SE 301";
            courses[choice].set_Course_Name("SE 301", 5);

            filename = "SE 301.bin";
            break;
        case 6:
            // courses[choice] = "CS 501";
            courses[choice].set_Course_Name("CS 501", 6);

            filename = "CS 501.bin";
            break;
        case 7:
            // courses[choice] = "CS 407";
            courses[choice].set_Course_Name("CS 407", 7);

            filename = "CS 407.bin";
            break;
        case 8:
            // courses[choice] = "CS 307";
            courses[choice].set_Course_Name("CS 307", 8);

            filename = "CS 307.bin";
            break;
        case 9:
            // courses[choice] = "CS 601";
            courses[choice].set_Course_Name("CS 607", 9);

            filename = "CS 601.bin";
            break;
        case 10:
            // courses[choice] = "CS 409";
            courses[choice].set_Course_Name("CS 409", 10);

            filename = "CS 409.bin";
            break;
        case -1:
            cout << "\nExiting..." << endl
                 << endl;
            cout << "\n***********************************\n\n";
            return false;

            break;
        default:
            cout << "\nInvalid choice!\n";
            break;
        }
        return true;
        cout << "\n***********************************\n\n";
    }
    void set_password()
    {
        password.setPasswordrows(1);
        password.set_password(0);
    }
    void view_password()
    {
        password.display_Password(0);
    }
    void Generate_Quiz()
    {
        try
        {
            Q.generate_Quiz(courses[choice]);
        }
        catch (const char *error)
        {
            cout << error << endl;
        }

        Q.save();
    }
    void view_Quiz()
    {
        cout << "\nQuiz\n***********************************\n\n";

        Q.read();

        cout << "\n***********************************\n";
    }
    void create_QuestionBank()
    {
        int select;

        cout << "\n1. Add Questions to new Topic\n"
             << "2. Add Question to existing Topic\n"
             << "Enter : ";
        cin >> select;

        switch (select)
        {
        case 1:
            add_new_Topics(); // add question to new topics
            break;
        case 2:
            add_Question_to_existing_Topics(); // add question to existing topics
            break;
        }
    }
    void add_new_Topics()
    {
        int topics;

        cout << "How many Topics do you want to Add in the Course : ";
        cin >> topics;
        cin.ignore();

        int *Qs = new int[topics];

        for (int i = 0; i < topics; i++)
        {
            courses[choice].ADD_T();
            cin.ignore();
        }

        for (int i = 0; i < topics; i++)
        {
            courses[choice].Add_Q_to_Topic();
        }
        courses[choice].Save(filename);
    }
    void add_Question_to_existing_Topics()
    {
        Load_Course();

        if (courses[choice].get_total_topics() > 0)
        {
            courses[choice].Add_Q_to_Topic();
            courses[choice].Save(filename);
        }
        else
            cout << "There are no topics\n";
    }
    void Load_Course()
    {
        courses[choice].Load(filename);
    }
    string get_Name()
    {
        return name;
    }
    void View_MarkSheet()
    {
        Q.view_MarkSheet();
    }
    void view_QuestiobBank()
    {
        courses[choice].display_All_Topic_Qs();
    }
    bool Teacher_sign_in()
    {
        return t.teacher_Sign_In();
    }
    bool Teacher_Log_in()
    {
        return t.teacher_Log_In();
    }
    void Teacher_save()
    {
        ofstream f_write("Teacher.bin", ios::out | ios::binary);
        f_write.write((char *)this, sizeof(*this));
        f_write.close();
    }
    void Teacher_read()
    {
        ifstream f_read("Teacher.bin", ios::in | ios::binary);
        if (!f_read)
        {
            cout << "Error opening file!\n";
            return;
        }
        f_read.read((char *)this, sizeof(*this));
        f_read.close();
    }
    void display_teacher()
    {
        cout << "Teacher Name : " << name << endl;
        cout << "Teacher Password : ";
        password.display_Password(index);
    }
    string HidePassword(string password)
    {
        char c;

        while ((c = getch()) != '\r')
        {
            if (c == '\b')
            { // handle backspace
                if (password.length() > 0)
                {
                    password.erase(password.length() - 1); // remove last character from password string
                    cout << "\b \b";                       // move cursor back, overwrite with space, move cursor back again
                }
            }
            else
            {
                password += c;
                cout << "*"; // print '*' instead of actual character
            }
        }

        return password;
    }
    void view_answer_key()
    {
        Q.Generate_Key();
    }
    void view_Attendance()
    {
        Q.view_attendance();
    }
    void view_Analytics()
    {
        Q.view_Graph();
    }
    void Teacher_set_NewPassword()
    {
        t.set_NewPassword();
    }
    void Teacher_delete_Topic()
    {
        courses[choice].remove_topic(filename);
        courses[choice].Save(filename);
    }
    void Teacher_delete_Question()
    {
        courses[choice].remove_Question(filename);
        courses[choice].Save(filename);
    }
};

class User : public Student, public Teacher
{
    int choice_user;
    int choice;
    bool checker;

public:
    User()
    {
        choice = 0;
        choice_user = 0;
        checker = false;
    }
    void Start()
    {
        cout << "\nUSER'S MENU\n***********************************\n";

        do
        {

            cout << "\nEnter User Mode \n"
                 << "1. Teacher \n"
                 << "2. Student \n"
                 << "3. Exit \n"
                 << "Enter : ";
            cin >> choice_user;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears all character input
                cout << "\nERROR : INVALID ENTRY\nEnter [1-3]" << endl;
            }
        } while (choice_user != 1 && choice_user != 2 && choice_user != 3);

        if (choice_user != 3)
            Log_Sign_In();
        else
            cout << "\nExiting...\n\n***********************************\n\n";
    }
    void Log_Sign_In()
    {
        cout << "\nLOG/SIGN IN\n***********************************\n";

        if (choice_user == 1) // Teacher Mode
        {
            do
            {
                cout << "\nDo you want to : \n"
                     << "1. Log in\n"
                     << "2. Sign in\n"
                     << "3. Go to Teacher Menu\n"
                     << "0. Exit\n"
                     << "Enter : ";
                cin >> choice;

                if (cin.fail())
                {
                    cin.clear();                                         // Clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears all characters input / ignores them
                    cout << "\nERROR : INVALID ENTRY.\nEnter [0-3]" << endl;
                }
                else
                    cin.ignore();

                if (choice == 1)
                    checker = Teacher_Log_in();
                else if (choice == 2)
                    checker = Teacher_sign_in();
                else if (choice == 3)
                {
                    if (checker == true)
                    {
                        Teacher_Menu();
                        break;
                    }
                    else
                        cout << "\nNOT LOGGED/SIGNED IN!\n";
                }
                else if (choice == 0)
                {
                    cout << "\nExiting...\n\n";
                    // return;
                }

            } while (choice);
        }
        else if (choice_user == 2) // Student Mode
        {
            do
            {
                cout << "\nDo you want to : \n"
                     << "1. Log in\n"
                     << "2. Sign in\n"
                     << "3. Go to Student Menu\n"
                     << "0. Exit\n";
                cin >> choice;

                if (cin.fail())
                {
                    cin.clear();                                         // Clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears all characters input / ignores them
                    cout << "\nERROR : INVALID ENTRY.\nEnter [0-3]" << endl;
                }

                if (choice == 1)
                    checker = student_LogIn();
                else if (choice == 2)
                    checker = student_SignIn();
                else if (choice == 3)
                {
                    if (checker == true)
                    {
                        Student_Menu();
                        break;
                    }
                    else
                        cout << "\nNOT LOGGED/SIGNED IN!\n";
                }
                else if (choice == 0)
                    cout << "\nExiting...\n\n";

            } while (choice);
        }
    }
    void Student_Menu()
    {
        do
        {
            cout << "\nSTUDENTS'S MENU\n***********************************\n";

            cout << "\n1. Attempt Quiz" << endl
                 << "2. View Marks" << endl
                 << "3. Change Passwords" << endl
                 << "0. Exit" << endl
                 << "Enter : ";
            cin >> choice;

            cout << endl;

            switch (choice)
            {
            case 1:
                attempt_Quiz();
                break;
            case 2:
                View_Marks();
                break;
            case 3:
                Student_change_password();
            case 0:
                cout << "\nExiting..." << endl;
                break;

            default:
                break;
            }

            cout << "\n***********************************\n";

        } while (choice);
    }
    void Teacher_Menu()
    {
        checker = false;
        checker = choose_course();
        Load_Course();

        if (checker == true)
            do
            {
                cout << "\nTEACHER'S MENU\n***********************************\n";

                cout << "\n1. Add Question to Question Bank" << endl
                     << "2. View Question Bank" << endl
                     << "3. Generate Quiz" << endl
                     << "4. View Quiz" << endl
                     << "5. View MarkSheet" << endl
                     << "6. View Answer Key" << endl
                     << "7. View Attendance" << endl
                     << "8. View Quiz Analytics" << endl
                     << "9. Change Password" << endl
                     << "10. Delete Topic" << endl
                     << "11. Delete Question" << endl
                     << "0. Exit" << endl
                     << "Enter : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    // cin.ignore();
                    create_QuestionBank();
                    break;
                case 2:
                    view_QuestiobBank();
                    break;
                case 3:
                    Generate_Quiz();
                    break;
                case 4:
                    view_Quiz();
                    break;
                case 5:
                    View_MarkSheet();
                    break;
                case 6:
                    view_answer_key();
                    break;
                case 7:
                    view_Attendance();
                    break;
                case 8:
                    view_Analytics();
                    break;
                case 9:
                    Teacher_set_NewPassword();
                    break;
                case 10:
                    Teacher_delete_Topic();
                    break;
                case 11:
                    Teacher_delete_Question();
                    break;
                case 0:
                    cout << "\nExiting..." << endl;
                    break;

                default:
                    break;
                }

                cout << "\n***********************************\n";

            } while (choice);
    }
};

// ! Main Function

int main()
{
    User user;
    user.Start();

    return 0; // * best Ma'am Khadija 100% sure I am
}
