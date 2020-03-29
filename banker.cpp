#include<iostream>
#include<vector>

using namespace std;

int main() {
    int work[4];
    int allocation[5][4];
    int max[5][4];
    int need[5][4];
    int m, n, r, a, available[4], required[4];
    bool state[5], test;
    vector < int > avl;
    //----------------------------------------
    test = true;
    for (int x = 0; x < 4; x++)
        work[x] = available[x];
    for (int x = 0; x < 5; x++)
        state[x] = false;
    //----------------------------enter p r---------------------------------
    cout << "Enter the number of processes in the system :";
    cin >> m;
    cout << "\nEnter the number of recourses :";
    cin >> r;
    //---------------------enter alloc---
    cout << "\nEnter the allocation " << endl;
    if (r = 1)
    {
        cout << "\t A \n \t ";
    }
    else if (r = 2)
    {
        cout << "\t A B \n \t ";
    }
    else if (r = 3)
    {
        cout << " A B C\n \t ";
    }
    else if (r = 4)
    {
        cout << " A B C D\n \t ";
    }
    for (int x = 0; x < m; x++)
    {
        cout << endl << "\t" << "P" << x << ":";
        for (int j = 0; j < 4; j++)
        {
            cin >> allocation[x][j];
            cout << " ";
        }
    }
    //-----------------------------entet max----------------
    cout << "\nEnter the MAX" << endl;
    if (r = 1)
        cout << " A \n \t ";
    else if (r = 2)
        cout << " A B \n \t ";
    else if (r = 3)
        cout << " A B C\n \t ";
    else if (r = 4)
        cout << " A B C D\n \t ";
    for (int x = 0; x < m; x++)
    {
        cout << endl << "P" << x << ":";
        for (int j = 0; j < 4; j++)
        {
            cin >> max[x][j];
            need[x][j] = max[x][j] - allocation[x][j];
        }
    }
    //-----------------enter ava--------------
    cout << "\nEnter the avaliable number : " << endl;
    for (int x = 0; x < 4; x++)
    {
        cin >> available[x];
        cout << " ";
    }
    //-----------------enter request--------------
    cout << "\nEnter the number of process want be request  : ";
    cin >> n;
    cout << "\nEnter the request number : " << endl;
    for (int x = 0; x < 4; x++)
    {
        cin >> required[x];
        cout << " ";
    }
    //-----------------------------------COUT---------------------
    cout << endl << "There are " << m << " processes in the system." << endl << endl;
    cout << "There are " << r << " resource types." << endl << endl;
    //----------------------------------cout allocation---------------
    cout << " The allocation Matrix : " << endl << endl;
    cout << "\t  A B C D";
    for (int x = 0; x < m; x++)
    {
        cout << endl << "\tP" << x << ":";
        for (int j = 0; j < 4; j++)
        {
            cout << allocation[x][j] << " ";
        }
        cout << endl;
    }
    //----------------------------------cout max---------------
    cout << endl << " The Max Matrix is...  " << endl << endl;
    cout << "\t  A B C D";
    for (int x = 0; x < m; x++)
    {
        cout << endl << "\tP" << x << ":";
        for (int j = 0; j < 4; j++)
        {
            cout << max[x][j] << " ";
        }
        cout << endl;
    }
    //-------------------------cout need-------------------------------------------
    cout << endl << " The Need Matrix is...  " << endl << endl;
    cout << "\t  A B C D";
    for (int x = 0; x < m; x++)
    {
        cout << endl << "\tP" << x << ":";
        for (int j = 0; j < 4; j++)
        {
            cout << need[x][j] << " ";
        }
        cout << endl;
    }
    //----------------------------- cout aval ---------------------
    cout << endl << "The Available Vector is..." << endl << endl;
    cout << "A B C D" << endl;
    for (int x = 0; x < 4; x++)
    {
        cout << available[x] << " ";
    }
    //-----------------------------------SAFE STATE-----------------------
    int k = 0;
    for (k = 0; k < m; k++) {
        if (state[k] == false) {
            test = false;
            for (int j = 0; j<r; j++) {
                if (need[k][j] > work[j])
                    break;
                if (need[k][j] <= available[j])
                    test = true;
            }
        }
    }
    if (test == true) {
        for (int j = 0; j < r; j++)
        {
            work[j] = work[j] + allocation[k][j];
        }
        state[k] = true;
        cout << endl << endl << "THE SYSTEM IS IN A SAFESTATE!" << endl;
    }
    if (test == false) {
        state[k] = false;
        cout << endl << endl << "THE SYSTEM IS NOT IN A SAFE STATE!";
    }
    //-----------------------------------request------------------------
    cout << "\nThe Request Vector is..." << endl;
    cout << "  A B C D" << endl;
    cout << n << ":";
    for (int x = 0; x < 4; x++)
    {
        cout << required[x] << " ";
    }
    bool test2 = false;
    for (int x = 0; x < m; x++) {
        if (n == m) {
            for (int j = 0; j < 4; j++)
            {
                if (required[j] <= avl[j] && required[j] <= need[x][j])
                {
                    test2 = true;
                }
                else
                {
                    break;
                }
            }
            if (test2 = true)
            {
                for (int n = 0; n < r; n++)
                {
                    available[n] = available[n] - required[n];
                    allocation[x][n] = allocation[x][n] + required[n];
                    need[x][n] = need[x][n] - required[n];
                }
                cout << "THE REQUEST CAN BE GRANTED!" << endl << endl;
                cout << "The Available Vector is...";
                cout << "A B C D" << endl;
                for (int x = 0; x < r; x++)
                {
                    cout << available[x] << " ";
                }
            }
            else
            {
                cout << "THE REQUEST CANNOT BE GRANTED!" << endl << endl;
            }
        }
    }

    //------------------------------------------------------------------------------


    return 0;
}
