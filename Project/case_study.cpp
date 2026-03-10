#include <iostream>
using namespace std;

// Global variables
int score = 0;
bool quizAttempted = false;
string results[3]; // store correct/wrong for each question

// Function to display instructions
void showInstructions() {
    cout << "\n===== QUIZ INSTRUCTIONS =====\n";
    cout << "1. The quiz contains 3 questions.\n";
    cout << "2. Each question has 4 options.\n";
    cout << "3. Enter the option number (1-4).\n";
    cout << "4. If you enter a number outside 1-4, it will show 'Invalid Answer'.\n";
    cout << "5. Each correct answer gives 1 mark.\n";
    cout << "==============================\n\n";
}

// Function to ask question
void askQuestion(int index, string question, string op1, string op2, string op3, string op4, int correct) {

    int answer;

    while(true) {

        cout << question << endl;
        cout << "1. " << op1 << endl;
        cout << "2. " << op2 << endl;
        cout << "3. " << op3 << endl;
        cout << "4. " << op4 << endl;

        cout << "Enter your answer (1-4): ";
        cin >> answer;

        if(answer < 1 || answer > 4) {
            cout << "Invalid Answer. Please try again.\n\n";
        }
        else {

            if(answer == correct) {
                score++;
                results[index] = "Correct";
            }
            else {
                results[index] = "Wrong";
            }

            break;
        }
    }
}

// Function to start quiz
void startQuiz() {

    score = 0;
    quizAttempted = true;

    showInstructions();

    askQuestion(0,"Q1. What is the capital of India?",
                "Mumbai","Delhi","Chennai","Kolkata",2);

    askQuestion(1,"\nQ2. Which language is used for system programming?",
                "Python","HTML","C++","CSS",3);

    askQuestion(2,"\nQ3. 2 + 2 = ?",
                "3","4","5","6",2);

    cout << "\nQuiz Completed!\n";
}

// Main function
int main() {

    int choice;

    do {

        cout << "\n===== ONLINE QUIZ SYSTEM =====\n";
        cout << "1. Start Quiz\n";
        cout << "2. View Score\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                startQuiz();
                break;

            case 2:

                if(!quizAttempted)
                {
                    cout << "\nYou have not attended the quiz yet.\n";
                }
                else
                {
                    cout << "\n===== QUIZ RESULT =====\n";

                    for(int i = 0; i < 3; i++)
                    {
                        cout << "Q" << i+1 << " - " << results[i] << endl;
                    }

                    cout << "\nFinal Score: " << score << " / 3\n";
                }

                break;

            case 3:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Menu Choice\n";
        }

    } while(choice != 3);

    return 0;
}