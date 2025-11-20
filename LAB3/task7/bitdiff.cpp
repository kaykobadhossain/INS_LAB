// bitdiff.c
#include <stdio.h>
#include <string.h>

void count_diff_bits(const char *h1, const char *h2) {
    int same = 0, total = 0;
    for (int i = 0; i < strlen(h1); i++) {
        unsigned char c1 = h1[i], c2 = h2[i];
        for (int b = 0; b < 8; b++) {
            if ((c1 & 1) == (c2 & 1)) same++;
            c1 >>= 1; c2 >>= 1; total++;
        }
    }
    printf("Total bits: %d\nSame bits: %d\nDifferent bits: %d (%.2f%%)\n", 
           total, same, total-same, 100.0*(total-same)/total);
}

int main() {
    const char *md5_h1 = "e4031329777e16fc696917f5a012722b";
    const char *md5_h2 = "adb5dc286803a37e21ce6a96640ee782";
    const char *sha_h1 = "1e634d9dd3fbd883e3ed7be23a15bbc7234385260884763f60402aba4ed76e29";
    const char *sha_h2 = "4faa10491de0a515fa7f41499b79371ea1c268f42b68b46f01cc4daf12cbc9b8";

    printf("=== MD5 ===\n");
    count_diff_bits(md5_h1, md5_h2);

    printf("\n=== SHA256 ===\n");
    count_diff_bits(sha_h1, sha_h2);

    return 0;
}