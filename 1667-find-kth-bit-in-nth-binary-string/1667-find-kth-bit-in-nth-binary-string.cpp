class Solution {
public:
    char findKthBit(int n, int k) {
        const unsigned int MAGIC_NUM = 0x464e46ce;
        
        int magicIndex = (k-1) & 0x1f;
        if (magicIndex != 15 && magicIndex != 31)
            return '0' + ((MAGIC_NUM >> magicIndex) & 0x1);
        if (magicIndex == 15)
            return '1' - (((k-1) / 32) % 2);

        // If magic index equals 31
        bool isInverse = false;
        while (1) {
            // Find power 2 of k
            int m = 0;
            while ( ((k-1) >> (++m + 1)) > 0 );

            // Reverse
            k = (2 << m) - k;
            if (k == 0)
                return '1' - isInverse;

            isInverse = !isInverse;
        }

        return '0';
    }
};