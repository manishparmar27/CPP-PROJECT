#include <iostream>
#include <vector>

using namespace std;
double calculateCGPA(vector<double> grades, vector<int> credits, int numSubjects) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numSubjects; i++) {
        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    return (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    vector<double> grades(numSubjects);
    vector<int> credits(numSubjects);
    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter grade (on 10-point scale) for subject " << i + 1 << ": ";
        cin >> grades[i];

        cout << "Enter credit hours for subject " << i + 1 << ": ";
        cin >> credits[i];
    }
    double cgpa = calculateCGPA(grades, credits, numSubjects);
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}