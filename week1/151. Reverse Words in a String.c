
char* reverseWords(char* s) {
        int len = strlen(s);
    if (len == 0) return s;

    // Step 1: Reverse the entire string in place
    int left = 0, right = len - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    // Step 2: Reverse each word in the reversed string
    int start = 0, end = 0;
    while (end <= len) {
        if (s[end] == ' ' || s[end] == '\0') {
            // Reverse the word between start and end-1
            int wordLeft = start, wordRight = end - 1;
            while (wordLeft < wordRight) {
                char temp = s[wordLeft];
                s[wordLeft] = s[wordRight];
                s[wordRight] = temp;
                wordLeft++;
                wordRight--;
            }
            start = end + 1;  // Move to the next word
        }
        end++;
    }

    // Step 3: Clean up spaces (remove extra spaces)
    int i = 0, j = 0;
    while (s[j]) {
        // Skip leading spaces
        while (s[j] == ' ') {
            j++;
        }
        // Copy the word
        while (s[j] && s[j] != ' ') {
            s[i++] = s[j++];
        }
        // Skip spaces between words
        while (s[j] == ' ') {
            j++;
        }
        // Add a single space if there's another word
        if (s[j]) {
            s[i++] = ' ';
        }
    }
    s[i] = '\0';  // Null-terminate the string

    return s;

}
