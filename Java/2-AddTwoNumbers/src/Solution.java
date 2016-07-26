public class Solution {
	class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
			next = null;
		}
	}

	public ListNode convertToList(long value) {
		ListNode result = new ListNode((int) (value % 10));
		ListNode cursor = result;
		value /= 10;
		while (value > 0) {
			ListNode node = new ListNode((int) (value % 10));
			cursor.next = node;
			cursor = node;
			value /= 10;
		}
		return result;
	}

	public long convertToLong(ListNode l1) {
		long value = 0;
		long ratio = 1;
		while (l1 != null) {
			value += l1.val * ratio;
			l1 = l1.next;
			ratio *= 10;
		}
		return value;
	}

	public void printNumber(ListNode e) {
		while (e != null) {
			System.out.format("%d", e.val);
			e = e.next;
		}
		System.out.format("\n");
	}

	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		long op1 = convertToLong(l1);
		long op2 = convertToLong(l2);
		return convertToList(op1 + op2);
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		ListNode n1 = s.convertToList(Long.parseLong("9"));
		ListNode n2 = s.convertToList(Long.parseLong("99999999991"));
		s.printNumber(n1);
		s.printNumber(n2);
		ListNode res = s.addTwoNumbers(n1, n2);
		s.printNumber(res);
	}

}