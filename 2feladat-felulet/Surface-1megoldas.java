import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.logging.Logger;

public class Surface {
		
	public static void print(double[][] coordinates) {
		for(double[] row : coordinates) {
			System.out.println(Arrays.toString(row));
		}
	}
	
	public static void main(String args[]) throws IOException {
		
		double[][] coordinates = new double [51][51];
		
		for(int i = 0; i <= 50; i++) {
			for(int j = 0; j <= 50; j++) { 
				if(i == 0 && j == 0) {
					coordinates[i][j] = 0;
				} else if(i == 50 && j == 0) {
					coordinates[i][j] = 0;
				} else if(i == 0 && j == 50) {
					coordinates[i][j] = 0;
				} else if(i == 50 && j == 50) {
					coordinates[i][j] = 0;
				} else if(i == 0) {
					coordinates[i][j] = 10.0;
				} else if(i == 50) {
					coordinates[i][j] = 20.0;
				} else if(j == 0) {
					coordinates[i][j] = -20.0;
				} else if(j == 50) {
					coordinates[i][j] = -10.0;
				} else {
					coordinates[i][j] = (coordinates[i][j-1]+coordinates[i-1][j]+coordinates[i][j+1]+coordinates[i+1][j])/4;
				}
			}
		}
		
		for(int k = 0; k < 100; k++ ) {
		for(int i = 0; i <= 50; i++) {
			for(int j = 0; j <= 50; j++) { 
				if(i == 0 && j == 0) {
					coordinates[i][j] = 0;
				} else if(i == 50 && j == 0) {
					coordinates[i][j] = 0;
				} else if(i == 0 && j == 50) {
					coordinates[i][j] = 0;
				} else if(i == 50 && j == 50) {
					coordinates[i][j] = 0;
				} else if(i == 0) {
					coordinates[i][j] = 10.0;
				} else if(i == 50) {
					coordinates[i][j] = 20.0;
				} else if(j == 0) {
					coordinates[i][j] = -20.0;
				} else if(j == 50) {
					coordinates[i][j] = -10.0;
				} else {
					coordinates[i][j] = (coordinates[i][j-1]+coordinates[i-1][j]+coordinates[i][j+1]+coordinates[i+1][j])/4;
				}
			}
		}
		}
		
		print(coordinates);
		
		StringBuilder builder = new StringBuilder();
		for(int i = 0; i < coordinates.length; i++)
		{
		   for(int j = 0; j < coordinates.length; j++)
		   {
		      builder.append(coordinates[i][j]+"");
		      if(j < coordinates.length - 1)
		         builder.append(",");
		   }
		   builder.append("\n");
		}
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		writer.write(builder.toString());
		writer.close();
	}
}
