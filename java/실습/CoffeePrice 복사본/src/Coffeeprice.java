import java.util.Scanner;

public class Coffeeprice {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("무슨 커피를 드릴까요? : ");
		String Order = scanner.next();
		
		int price = 0;
		switch(Order) {
		case "에스프레소" : 
		case "카푸치노" :
		case "카페라뗴" :
			price = 3500;
			break;
		case "아메리카노" :
			price = 2000;
			break;
			default :
				System.out.println("메뉴에 없습니다.");
				break;
		}
		if(price!= 0)
	System.out.println(Order + "는 " + price + "원입니다.");
		scanner.close();
	}
}