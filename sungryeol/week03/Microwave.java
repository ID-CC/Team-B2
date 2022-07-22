package week03;

import java.util.Scanner;

public class Microwave {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String time = scanner.next();

        microwave(time);
    }
    public static void microwave(String time) {
        int cnt = 0;
        String[] ms = time.split(":");
        int sec = Integer.parseInt(ms[0]) * 60 + Integer.parseInt(ms[1]);
        int loopCnt = 0;
        boolean started = false;

        while(sec > 0) {
            if( sec >= 600) {
                sec -= 600;
                cnt++;
                loopCnt++;
            } else if(sec >= 60) {
                sec -= 60;
                cnt++;
                loopCnt++;
            } else if(sec >= 30) {
                if(loopCnt == 0 && !started) started = true;
                sec -= 30;
                cnt++;
                loopCnt++;
            } else if(sec >= 10) {
                sec -= 10;
                cnt++;
                loopCnt++;
            }
        }
        cnt = (started) ? cnt : cnt + 1;

        System.out.println(cnt);
    }
}