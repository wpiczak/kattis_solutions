#include <bits/stdc++.h>

int main() {
    int day;
    char month[4];
    scanf("%s %d", &month, &day);
    if (std::string(month) == "OCT" && day == 31)
        printf("yup");
    else if (std::string(month) == "DEC" && day == 25)
        printf("yup");
    else printf("nope");
    return 0;
}
