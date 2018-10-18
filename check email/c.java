import java.util.Scanner;
/**
 * Check email code
 *
 * @Zeyu Cheng
 * @1017
 */
public class c
{
    public static void main(String[] arg){
        Scanner scan = new Scanner(System.in);
        System.out.print("Plz enter your sjsu email: ");
        while(scan.hasNextLine()){
            String e = scan.nextLine();
            String s = "";
            for(int i = 0; i < e.length(); i++){
                 if(e.substring(i,i+1).equals("@")){
                     String a = e.substring(i+1, e.length());
                     if(a.equals("sjsu.edu")){
                         s = "login success";
                         System.out.println(s);
                         break;
                     }
                     else{
                         System.out.println("wrong email");
                     }
                 }
            }
            if(s.equals("login success")){
                    break;
                }
            else{
                    System.out.print("Plz enter your sjsu email: ");
            }
        }
    }
}
