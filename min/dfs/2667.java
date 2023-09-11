import java.io.*;
import java.util.*;

public class Main { // dfs,재귀로 구현!
    public static int n; // n*n
    public static int[][] graph;// 단지정보
    public static int[] dx = { -1, 1, 0, 0 }; // 상하좌우
    public static int[] dy = { 0, 0, -1, 1 };
    public static boolean[][] visited; // 방문정보
    public static int cnt; // 단지별 집수
    public static ArrayList<Integer> result = new ArrayList<>(); // 최종 단지에 대한 정보

    public static void main(String[] args) throws IOException {// BufferedReader 사용위해 io excexception 해야댐
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        graph = new int[n][n];
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            // 단지정보 입력받기
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(str.substring(j, j + 1));
            }
        }
        // 0,0부터 탐색시작
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    cnt = 0;
                    dfs(i, j);
                    result.add(cnt);// 최종 단지리스트에 집수 추가
                }
            }
        }

        Collections.sort(result);// 오름차순 정렬
        System.out.println(result.size());
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }

    }

    // dfs 구현
    public static void dfs(int row, int col) {
        cnt += 1; // 집수 증가
        visited[row][col] = true; // 해당 노드 방문했으므로 방문처리

        // 상하좌우로 탐색
        for (int i = 0; i < 4; i++) {
            int row2 = row + dx[i];
            int col2 = col + dy[i];
            // 범위를 벗어나는지 체크
            if (row2 < 0 || row2 >= n || col2 < 0 || col2 >= n) {
                continue;
            } else if (graph[row2][col2] == 1 && !visited[row2][col2]) {
                dfs(row2, col2);
            }
        }

    }

}
