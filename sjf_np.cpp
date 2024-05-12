
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Matrix for storing Process Id, Burst Time, Waiting Time, Turnaround Time.
    int A[100][5];
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Burst Time:" << endl;

    // User Input Burst Time and alloting Process Id.
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> A[i][1];
        A[i][0] = i + 1;
    }

    // Sorting process according to their Burst Time.
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                index = j;
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    A[0][2] = 0;
    // Calculation of Waiting Times
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }

    avg_wt = (float)total / n;
    total = 0;

    // Printing Gantt Chart Header
    cout << "Gantt Chart:" << endl;
    cout << setw(5) << "Time" << " | ";
    for (i = 0; i < n; i++) {
        cout << setw(5) << "P" << A[i][0] << " | ";
    }
    cout << endl;

    cout << setw(5) << "-----" << "-+-";
    for (i = 0; i < n; i++) {
        cout << setw(5) << "-----" << "-+-";
    }
    cout << endl;

    // Printing Gantt Chart Rows
    cout << setw(5) << "0" << " | ";
    for (i = 0; i < n; i++) {
        cout << setw(5) << A[i][2] << " | ";
    }
    cout << A[n - 1][3] << endl;

    // Calculation of Turn Around Time and printing the data.
    cout << "P\tBT\tWT\tTAT" << endl;
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        cout << "P" << A[i][0] << "\t" << A[i][1] << "\t" << A[i][2] << "\t" << A[i][3] << endl;
    }

    avg_tat = (float)total / n;
    cout << "Average Waiting Time= " << avg_wt << endl;
    cout << "Average Turnaround Time= " << avg_tat << endl;

    return 0;
}

