#include<iomanip>
#include<iostream>
#include "astarmod1.cpp"
#include "audio.cpp"
#include "phonebook.cpp"
using namespace std;
void incoming()
{
    cout<<endl<<"Music paused...";
    cout<<endl<<"Navigation stopped...";
    cout<<endl<<"Reverse cam stopped...";
    char iname[30],iphone[30];
    int itime;
    filee.open("Calls.bin",ios::binary|ios::app);
    cout<<endl<<"\t Enter contact name : ";
    cin>>iname;
    cout<<endl<<"\t Enter phone number : ";
    cin>>iphone;
    cout<<endl<<"\t Enter duration (mins) : ";
    cin>>itime;
    s.push(iname,iphone,itime);
    cal.insert(iname,iphone,itime);
    filee.write((char *)&cal,sizeof(cal));
    filee.close();

}
void reversecam()
{
    cout<<endl<<"Music paused...";
    cout<<endl<<"Navigation stopped...";
    cout<<endl<<"Press 1 for incoming call. 0 to ignore.";
    int op;
    cin>>op;
    if (op==1)
    {
        incoming();
    }

    else if (op!=0)
    {
        cout<<"Invalid input. Continuing."<<endl;
    }
}
int main()
{
    int ch;
    do
    {
        cout<<endl<<"\t\t-------------------";
        cout<<endl<<"\t\t    INFOTAINMENT";
        cout<<endl<<"\t\t-------------------";
        cout<<endl<<"\n\t\t1. Navigation";
        cout<<endl<<"\t\t2. Audio system";
        cout<<endl<<"\t\t3. Phonebook";
        cout<<endl<<"\t\t4. Incoming call";
        cout<<endl<<"\t\t5. Reverse camera";
        cout<<endl<<"\t\t6. Exit";
        cout<<endl<<"\t Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:navigation();break;
            case 2:audioplayer();break;
            case 3:phonebook();break;
            case 4:incoming();break;
            case 5:reversecam();break;
            case 6:return 0;
        }
    }while(ch!=6);
}
