#include <iostream>

int main() {
    int x;
    std::cout << "enter number of task: 1-3(0 for exit)\n";
    while(1){
    std::cin >>x;
    switch(x){
        case 1:{
        int a = 3, c = 2;
    int* p;
    p = &a;
    std::cout << p << " - Address of a\n";
    std::cout << *p << "- value of a \n";
    *p *= 3;
    std::cout << *p << " -value of a *3\n";
    *p += c;
    std::cout << *p << " -value of a + c\n";
    p = &c;
    std::cout << *p << " - value of c\n";
    std::cout << a << " - value of a\n";
    std::cout << &p << " address of p\n";
    std::cout << p << "address of c\n";
    break;
        }
        case 2:
    {
        int a, b, c;
        std:: cout << "enter a, b, c\n";
        std::cin >> a >> b >> c;
        int* p_a = &a;
        int* p_b = &b;
        int* p_c = &c;

        int* max_p = &a;
        int* min_p = &a;
        if(*p_a > *p_b &&  *p_a > *p_c){
            max_p = p_a;
        }
        else if(*p_b > *p_a && *p_b > *p_c){
            max_p = p_b;
        }
        else{
            max_p = p_c;
        }
        std::cout << "max: " << *max_p << "\n";
        std::cout<< "min = "<< *min_p <<"\n";
        std::cout << "Address of max:  " << max_p << "\n";
        std::cout<< "Address of min: "<< min_p <<"\n";
    
    break;
    }
    case 3:
    {
        int a, b, c, d;
         int* p_a = &a;
        int* p_b = &b;
        int* p_c = &c;
        int* p_d = &d;
        while(1){
            std:: cout << "enter a, b, c, d\n";
        std::cin >> a >> b >> c >> d;
       
        if(*p_a != *p_b || *p_a != *p_c || *p_a != *p_d || *p_b != *p_c || *p_b != *p_d || *p_c != *p_d){
            std::cout << "enter unique numbers\n";
        }
        else{
            break;
        }
    }
        int* max_p = &a;
        int* min_p = &a;
        int sum = *p_a + *p_b + *p_c + *p_d;
        int *p_sum = &sum;
        std::cout << "average: " <<*p_sum/4 << "\n";
        if(*p_a > *p_b &&  *p_a > *p_c && *p_a > *p_d){
            max_p = p_a;
        }
        else if(*p_b > *p_a && *p_b > *p_c & *p_b > *p_d){
            max_p = p_b;
        }
        else if (*p_c > *p_a && *p_c > *p_b && *p_c > *p_d){
            max_p = p_c;
        }
        else{
            max_p = p_d;
        }
        if(*p_a < *p_b &&  *p_a < *p_c && *p_a < *p_d){
            min_p = p_a;
        }
        else if(*p_b < *p_a && *p_b < *p_c & *p_b < *p_d){
            min_p = p_b;
        }
        else if (*p_c < *p_a && *p_c < *p_b && *p_c < *p_d){
            min_p = p_c;
        }
        else{
            min_p = p_d;
        }
        if(*p_a != *max_p && *p_a != *min_p){
            std::cout << "nor max nor min " << *p_a << "\n";
        }
        if(*p_b != *max_p && *p_b != *min_p){
            std::cout << "nor max nor min " << *p_b << "\n";
        }
        if(*p_c != *max_p && *p_c != *min_p){
            std::cout << "nor max nor min " << *p_c << "\n";
        }
        if(*p_d != *max_p && *p_d != *min_p){
            std::cout << "nor max nor min " << *p_d << "\n";
        }
    }
    case 0: return 0;
    default:
    std::cout << "enter number of task: 1-3\n";
    break;
    }
}
return 0;
}
    