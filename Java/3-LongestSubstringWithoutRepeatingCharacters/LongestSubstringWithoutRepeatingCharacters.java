// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Peter-s

/**********************************************************************************
 *
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 **********************************************************************************/

public class LongestSubstringWithoutRepeatingCharacters {

	public int lengthOfLongestSubstring(String s) {
		int ascii_size = 127;
		int i = 0, j = 0, k = 0;
		int [] repeat = new int[ascii_size];
		for(i = 0; i < ascii_size; i++) {
			repeat[i] = 0;
		}
		
		int len = s.length();
        char[] w = new char[len];
        w = s.toCharArray();

		int max_len = 0;
		int max_pos = 0;
		int longest = 0;
		
		for(i = 0; i < len; i++) {
			for(k = 0; k < ascii_size; k++) {
				repeat[k] = 0;
			}
			longest = 1;
			repeat[w[i]] = i+1;
			for(j = i+1; j < len; j++) {
				if(repeat[w[j]] == 0) {
					repeat[w[j]] = j+1;
					longest++;
				} else {
					break;
				}
			}
			if(max_len < longest) {
				max_len = longest;
				max_pos = i;
			}
		}
	
		System.out.println(max_len);
		return max_len;
	}

	public static void main(String[] args) {
		LongestSubstringWithoutRepeatingCharacters s = new LongestSubstringWithoutRepeatingCharacters();
		//String str = "pwwkew";
		//String str = "abcabcbb";
		 String str = "au";
		s.lengthOfLongestSubstring(str);
	}
}
