void insert(int* arr, int size, int item, int index) {
    int i;
    for(i = size; i>index && i != 0; i--)
        *(arr+i) = *(arr + i-1);
    *(arr+i) = item;
}
int pop(int* arr, int size, int index) {
    int toRet = *(arr +index);
    for (int i = index; i < size; i++){
        int a = *(arr + i);
        *(arr + i) = *(arr + i + 1);
        *(arr + i + 1) = a;
    }
    return toRet;
}
int binaryInsert(int* arr, int size, int search) {
    if(size == 0) return 0;
    int right = size - 1, left = 0, mid = size / 2;

    while (right - left > 0) {

        if (*(arr + mid) > search) { 
            right = mid - 1;
            mid = (right + left) / 2;
        }
        else if (*(arr + mid) < search) { 
            left = mid + 1;
            mid = (right + left) / 2;
        }
        else if (*(arr + mid) == search) 
            return mid;
    }
 
    if(right <= left){
        if(*(arr+mid) < search){
            return mid + 1;cout << "======" << endl;}
    }    return mid;

}

void lion_sort(int* arr, int length){
    int size, element, loc;
    for(size = 1; size < length; size++){
        element = pop(arr, size, size);
        loc = binaryInsert(arr, size, element);
        insert(arr, size, element, loc);
    }  
}
