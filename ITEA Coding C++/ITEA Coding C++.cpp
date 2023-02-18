#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class vecray
{
    T* vec;
    int size = 0;
    
public :


    ~vecray()
    {
        delete[]vec;
    }

    void operator+(T elem)
    {
        //vec = new int[size + 1];
        T* temp = new T[size + 1];
        if (vec)
        {
            for (int i = 0; i < size; i++)
                temp[i] = vec[i];
            delete[] vec;
        }
        vec = temp;
        vec[size] = elem;
        size++;
    }

    void operator--()
    {
        cout << endl << "The last element in a vecray is deleted" << endl;
        size--;
    }

    T operator~()
    {
        return vec[size - 1];
    }

    int len()
    {
        return size;
    }

    void print()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << vec[i] << ' ';
        }
        cout << endl;
    }
    void operator++()
    {
        cout << typeid(typeid(*vec).name()).name() << endl;
        int i = 0;
        double d = 0.0;
        if (typeid(*vec).name() == typeid(i).name() || typeid(*vec).name() == typeid(d).name())
        {
            T sum = 0;
                for (int i = 0; i < size; i++)
                {
                    sum += vec[i];
                }
                cout << endl << "The sum of its elements is : " << sum << endl;
        }
        else
        {
            cout << endl << "You can\'t sum up the elements of this vecray" << endl;
        }
    }
};

template<typename T>
void vec_realization(vecray<T> vec)
{
    bool is = true;
    int n;
    T var;
    while (is)
    {
        cout << endl << "What do you wanna do\n1 - add element\n2 - delete element\n3 - get the last element\n4 - print the array\n5 - get element count\n6 - find the sum of elements\n0 - finish the program\n: ";
        cin >> n;

        switch (n)
        {
            case 1:
            {
                cout << endl << "Enter a variable : ";
                cin >> var;
                vec + var;
                break;
            }
            case 2:
            {
                --vec;
                break;        }
            case 3:
            {
                cout<< endl << "Your last element is : " << ~vec << endl;
                break;        }
            case 4:
            {
                vec.print();
                break;
            }
            case 5:
            {
                cout << "The size of your vecray is : " << vec.len() << endl;
                break;
            }
            case 6:
            {
                ++vec;
                break;
            }
            case 0:
            {
                cout << "Bye!" << endl;
                is = false;
                break;
            }
            default:
            {
                cout << "Invalid input!\nEnter again" << endl;
            }
        }
    }
}

int main()
{
    cout << "Which vector type do you want to create\n1 - int\n2 - double\n3 - char\n4 - string\n: ";
    int choice;

EnterAgain:

    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        vecray<int> vec;
        vec_realization(vec);
        break;
    }
    case 2:
    {
        vecray<double> vec;
        vec_realization(vec);
        break;
    }
    case 3:
    {
        vecray<char> vec;
        vec_realization(vec);
        break;
    }
    case 4:
    {
        vecray<string> vec;
        vec_realization(vec);
        break;
    }
    default:
    {
        cout << "Invalid input!\nEnter again" << endl;
        goto EnterAgain;
    }
    }

    return 0;
}