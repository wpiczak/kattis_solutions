#include <bits/stdc++.h>

int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while (caseCount--) {
        char name[31];
        int studyStartYear, birthYear, courseCount;
        scanf("%s %d/%*d/%*d %d/%*d/%*d %d", name, &studyStartYear, &birthYear, &courseCount);
        printf("%s ", name);
        if (studyStartYear >= 2010 || birthYear >= 1991) printf("eligible\n");
        else if (courseCount <= 40) printf("coach petitions\n");
        else printf("ineligible\n");
    }
    return 0;
}
