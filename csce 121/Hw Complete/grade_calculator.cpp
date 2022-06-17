
// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    double ExamGrades=0;
    double HomeworkGrades=0; // Student Notes I will add each value to the grades Column
    double LabworkGrades=0;
    double EngagementGrades=0; 
    double Final =0;
    double storage; //catches spelling mistakes in lw
    //double Storage;
    double DividenExam=0; // Student Notes These will be increment by 1 upward
    double DividenHomework=0;
    double DividenLabwork=0;
    double DividenEngagement=0;
    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
while (!line.empty()) {

        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry

        if (category == "exam") {
            // TODO(student): process exam score


            ExamGrades +=  score; // Student notes adding each score to the appropriate grade

            DividenExam++;



        }
         else if (category == "final-exam") {
            // TODO(student): process final score
            Final = score;
 // Student Notes: set the Final equal to the score
            

        } else if (category == "hw") {
            // TODO(student): process hw score

            HomeworkGrades += score; // Student notes adding each score to the appropriate grade
            DividenHomework++;


        } else if (category == "lw") {
            // TODO(student): process lw score
            storage = score;

            if (storage> 1){
                storage = 1;
            }


                LabworkGrades += storage*100; // Student notes adding each score to the appropriate grade
            
                DividenLabwork++;


        } else if (category == "engagement") {
            // TODO(student): process engagement score

            EngagementGrades += score; // Student notes adding each score to the appropriate grade
            
            DividenEngagement++;

        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);

    }

    // TODO(student): compute component averages

    if (EngagementGrades >100){
        EngagementGrades =100;
    }


    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double engagement = EngagementGrades;


    for (int i=0;i<10;i++)
    {


    
    if (DividenHomework !=0){
        hw_average = HomeworkGrades / DividenHomework;
    }
    if (DividenLabwork !=0){
        lw_average = LabworkGrades / DividenLabwork;
    }
    if (DividenExam !=0){
        
        exam_average = (ExamGrades+Final) / 3;
        if (Final > exam_average){
            exam_average = Final; //the final is the new exam average
        }


        }
    if (DividenExam == 0){
        exam_average = Final;
    }    
    }




    
    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    double ExamWeight;
    double HomeworkWeight;
    double EngangementWeight;
    double LabworkWeight;
    ExamWeight = exam_average*(.4); // 40%
    HomeworkWeight = hw_average*(.4); // 40%
    EngangementWeight = engagement*(.1); // 10%
    LabworkWeight = lw_average*(.1); // 10% 



    weighted_total = ExamWeight + HomeworkWeight + EngangementWeight + LabworkWeight; // total amount
    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total >= 89.5){
        final_letter_grade = 'A';
    }
    else if ((weighted_total>=79.5) && (weighted_total<89.5)) {
        final_letter_grade = 'B';
    }
    else if ((weighted_total>=69.5) && (weighted_total<79.5)){
        final_letter_grade = 'C';
    }
    else if ((weighted_total>=59.5) && (weighted_total<69.5)){
        final_letter_grade = 'D';
    }
    else {
        final_letter_grade = 'F';
    }
print_results(
        exam_average, hw_average, lw_average, engagement,
        weighted_total, final_letter_grade);


}
// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}

