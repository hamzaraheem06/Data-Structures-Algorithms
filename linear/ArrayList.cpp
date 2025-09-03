#include<iostream>

using namespace std;

class ArrayList {
private:
    int *arr;
    int curIndex;
    int curSize;
public:
    ArrayList(int initSize) {
        arr = new int[initSize];
        curSize = initSize;
        curIndex = 0;
    }

    void append(int value) {
        if(curIndex < curSize) {
            arr[curIndex] = value;
            curIndex++;
            return;
        }
        curSize = curSize * 2; // update the current size of the array
        int *newArr = new int[curSize];
        for(int i = 0; i < curIndex; i++) {
            newArr[i] = arr[i];
        }

        delete [] arr;
        arr = newArr;
        arr[curIndex] = value;
        curIndex++;

    }

    int indexOf(int value) {
        for (int i = 0; i < curIndex; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }

    void pop() {
        if (curIndex < 0) return;
        
        curIndex--;
    }

    void erase(int index) {
        if(index < 0 && index >= curIndex) return;

        if (index == curIndex - 1) {
            pop();
            return;
        }

        for (int i = index + 1; i < curIndex; i++) {
            arr[i - 1] = arr[i];
        }

        curIndex--;
    }

    int min() {
        int min = arr[0];
        for (int i = 1; i < curIndex; i++) {
            if (arr[i] < min) min = arr[i];
        }

        return min;
    }

    int max() {
        int max = arr[0];
        for (int i = 1; i < curIndex; i++) {
            if (arr[i] > max) max = arr[i];
        }

        return max;
    }

    void reverse() {
        int l = 0, r = curIndex - 1;

        while (l < r) {
            swap(arr[l], arr[r]);
            l ++;
            r --;
        }
    }

    ArrayList reverseCopy() {
        ArrayList rev(curIndex);

        for (int i = 0; i < curIndex; i++) {
            rev.append(arr[curIndex - i - 1]);
        }

        return rev;
    }

    void display() {
        string res = "[ ";
        for (int i = 0; i < curIndex; i++) {
            res.append(std::to_string(arr[i])); 
            if (i != curIndex - 1) res.append(", ");
        }
        res.append(" ]");
        cout<<res<<endl; 
    }

    ~ArrayList() {
        delete[] arr; // ✅ free memory
    }
};

int main() {
    ArrayList myList(3);

    myList.append(5);
    myList.append(-10);
    myList.append(15);
    myList.append(20);

    // myList.display();

    // myList.reverse();

    myList.display();

    ArrayList reversed = myList.reverseCopy();

    reversed.append(200);
    reversed.display();

    return 0;
}