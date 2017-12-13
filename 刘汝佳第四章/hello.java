public class Hello {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("输入字符串，exit终止====>");
        while (s.hasNextLine()) {
            String line = s.nextLine();
            if (line.equals("exit"))
                break;
            System.out.println("out==>"+line);
        }
    }
}