package Time_Interval;

public class MyDate {
	private int year;
	private int month;
	private int day;
	private MyDate(int y,int m,int d){
		year = y; month = m; day = d;
	}
	public static MyDate init(int y,int m,int d)throws Exception{
		if(y < 1 || m < 1 || m>12 || d<1){
			throw new Exception();
		}
		MyDate myDate=new MyDate(y,m,d);
		if(d>myDate.maxDay()){
			throw new Exception();
		}
		return myDate; 
	}
	public int maxDay(){
		int M[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (isLeapYear() && month == 2)
			return 29;
		else
			return M[month - 1];
	}
	public boolean isLeapYear(){
		return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
	}
	public int sub(MyDate myDate){
		return this.day_t() - myDate.day_t();
	}
	public int day_t(){
		int M[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int sum = 0;
		for (int i = 0; i < month - 1; i++)
			sum = sum + M[i];
		if (isLeapYear() && month>2)
			sum++;
		return 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + sum + day - 1;
	}
	
	public static void main(String[] args){
		System.out.println("start");
		long time1=System.currentTimeMillis();
		for(int i=2015;i<1000000;i++){
			MyDate myDate1;
			MyDate myDate2;
			try {
				myDate1 = MyDate.init(i,7,9);
				myDate2=MyDate.init(1995, 9, 11);
				myDate1.sub(myDate2);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		}
		long time2=System.currentTimeMillis();
		System.out.println(time2-time1);
	}
}
