char* gcdOfStrings(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    int n1 = strlen(str1);
    int n2 = strlen(str2);
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    int gcdLen = gcd(n1, n2);

    for (int i = 0; i < n1; i++) {
        if (str1[i] != str1[i % gcdLen]) {
            return strdup("");
        }
    }

    for (int i = 0; i < n2; i++) {
        if (str2[i] != str1[i % gcdLen]) {
            return strdup("");
        }
    }

    char* ans = (char*)malloc((gcdLen + 1) * sizeof(char));
    if (ans == NULL) {
        return NULL;
    }
    
    strncpy(ans, str1, gcdLen);
    ans[gcdLen] = '\0';
    
    return ans;
}
