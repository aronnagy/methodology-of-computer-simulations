import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.logging.Logger;

public class SelfAvoidingRandomWalk {
		
	public static void print(double[][] coordinates) {
		for(double[] row : coordinates) {
			System.out.println(Arrays.toString(row));
		}
	}
	
	public static void main(String args[]) throws IOException {
		
		Random rand = new Random();
		
		int direction = -1;
		double sum = 0;
		int steps = 0;
		
		int a = 1;
		int b = 1;
				
		double[][] coordinates = new double [51][51];
		double[][] moreCoordinates = coordinates;
		
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
					coordinates[i][j] = 0.0;
				}
			}
		}
				
		//for(int k = 0; k < 100; k++) {
		for(int i = 0; i <= 50; i++) {  
		for(int j = 0; j <= 50; j++) {
			
			a = i;
			b = j;
			
		do {
			direction = rand.nextInt(4);
			
			if(direction == 0) {
				b += 1;
				sum += -10.0;
			}
			else if(direction == 1) {
				b -= 1;
				sum += -20.0;
			}
			else if(direction == 2) {
				a += 1;
				sum += 20.0;
			}
			else {
				a -= 1;
				sum += 10.0;
			}
			steps++;
				
		}while(a != 0 && a != 50 && b != 0 && b != 50);
		
		if(i == 0 && j == 0) {
			moreCoordinates[i][j] = 0;
		} else if(i == 50 && j == 0) {
			moreCoordinates[i][j] = 0;
		} else if(i == 0 && j == 50) {
			moreCoordinates[i][j] = 0;
		} else if(i == 50 && j == 50) {
			moreCoordinates[i][j] = 0;
		} else if(i == 0) {
			moreCoordinates[i][j] = 10.0;
		} else if(i == 50) {
			moreCoordinates[i][j] = 20.0;
		} else if(j == 0) {
			moreCoordinates[i][j] = -20.0;
		} else if(j == 50) {
			moreCoordinates[i][j] = -10.0;
		} else {
			moreCoordinates[i][j] += sum / steps;
		}
		
		sum = 0;
		steps = 0;

		}
		}
		//}
			
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
				coordinates[i][j] = moreCoordinates[i][j];
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
		BufferedWriter writer = new BufferedWriter(new FileWriter("random-walk-output.txt"));
		writer.write(builder.toString());
		writer.close();
	}
}
