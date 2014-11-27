

import java.io.*;
import java.net.*;
import java.sql.SQLException;
import java.util.*;

public class MyServer {
	public static void main(String[] args) throws IOException, SQLException {
		
//		AP ap=new AP ("sddf",23,45);
//		
//		databaseUtil.insert(ap);
//		databaseUtil.query();
		
		
		ServerSocket server = new ServerSocket(24399);

		try {

			while (true) {
				Socket socket = server.accept();

				DataInputStream dis = new DataInputStream(
						socket.getInputStream());

				PrintWriter out = new PrintWriter(socket.getOutputStream());

				BufferedReader wt = new BufferedReader(new InputStreamReader(
						System.in));

				while (true) {
					// System.out.println("receiving");

					Thread.sleep(1000);
					
					byte[] b = new byte[1024];
					int i = dis.read(b);

					String str1 = new String(b, 0, i);
					System.out.println("RECEIVE MESSAGE: " + str1);
					
					String tmp[]=str1.split("_");
//					tmp[2]=tmp[2].substring(0, tmp[2].length()-2);
					
					
					
					
				
					
					AP ap= new AP(tmp[0],Integer.parseInt(tmp[1]),Integer.parseInt(tmp[2]));
					databaseUtil.insert(ap);

					// System.out.println("sending");

					Random rand = new Random();
					int channel = rand.nextInt(50) + 1;
					int power = rand.nextInt(50) + 1;

					String str = channel + "_" + power;

					out.print(str);
					out.flush();

					// System.out.println("sent");

					if (str.equals("end")) {

						break;

					}

				}

				socket.close();
			}
		} catch (Exception e) {
			server.close();
		}
	}
}