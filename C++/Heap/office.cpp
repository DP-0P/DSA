#include <iostream>
using namespace std;

class time
{
public:
    int hh;
    int mm;
    string ap;

    time(int hr, int mi, string appa)
    {
        hh = hr;
        mm = mi;
        ap = appa;
    }
};

class employee
{
public:
    time *arr;
    time *dep;

    employee(int ah, int am, string aap, int dh, int dm, string dap)
    {
        arr = new time(ah, am, aap);
        dep = new time(dh, dm, dap);
    }

    void incoming()
    {
        if (arr->ap == "am")
        {
            int hr = 9 - arr->hh;
            if (hr < 0)
            {
                if(-(hr)==1){
                    if(arr->mm>30)
                       cout << "Late by : " << -(hr) << " hr " << arr->mm - 30 << " min";

                    else if(arr->mm<30) 
                        cout<< "Late by : " << 30-arr->mm << " min";
                    
                    else
                        cout<< "Late by : "<< -hr << " hr";
                }
                else{
                    if(arr->mm < 30)
                        cout<< "Late by : " << -hr-1 << " hr " << 30 - arr->mm << " min";
                    else if(arr->mm >30)
                        cout<< "Late by : " << -hr << " hr " << arr->mm - 30 << " min";
                    else
                        cout<< "Late by : " << -hr<< " hr";
                }
            }
            else if (hr > 0)
            {
                if (hr == 1)
                {
                    if (arr->mm < 30)
                        cout << "Early by : " << hr << " hr " << 30 - arr->mm << " min"; //60-45+30==55

                    else if (arr->mm > 30)
                        cout << "Early by : " << 60 - arr->mm + 30 << " min";
                    
                    else 
                        cout<< "Early by : "<<hr << " hr";
                }

                else
                {
                    if(arr->mm < 30)
                        cout<< "Early by : " << hr << " hr " << 30 - arr->mm << " min";
                    else if(arr->mm >30)
                        cout<< "Early by : " << hr-1 << " hr " << 30 - arr->mm << " min";
                    else
                        cout<< "Early by :" << hr<< " hr";
                }
            }
            else{
                if(arr->mm<30)
                    cout<< "Early by : " << 30-arr->mm<< " min";
                else if(arr->mm>30)
                    cout<< "Late by : " << arr->mm-30 << " min";
                else
                    cout<< "On time";
            }
        }
    }
};

int main()
{
    employee *dp = new employee(9, 25, "am", 1, 2, " ");
    dp->incoming();
}