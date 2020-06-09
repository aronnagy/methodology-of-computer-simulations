package paraboloidVolume;

import java.util.ArrayList;

public class RiemannSum {
	
	public static void main(String args[]) {
		
		double volume = 0;
		double deltaA = 0.0078125;
		ArrayList<Double> n = new ArrayList<Double>();
		ArrayList<Double> m = new ArrayList<Double>();
		ArrayList<Double> pointValues = new ArrayList<Double>();
		ArrayList<Double> columnVolumes = new ArrayList<Double>();
		
		for(double i = -3; i <= 3; i=i+deltaA) {
			n.add(i);
			m.add(i);
		}
		
		for(int i = 0; i < n.size(); i++) {
			for(int j = 0; j < m.size(); j++) {
				pointValues.add(n.get(i)*n.get(i)+m.get(j)*m.get(j));
				System.out.println("(x: " + (i-3) + " y: " + (j-3) + ") = " + (n.get(i)*n.get(i)+m.get(j)*m.get(j)));
			}
		}
		System.out.println("column volume calculation");
		for(int i = 0; i < pointValues.size(); i++) {
				columnVolumes.add(pointValues.get(i)*deltaA*deltaA);
		}
		
		System.out.println("volume calculation");
		for(int i = 0; i < columnVolumes.size(); i++) {
				System.out.println(columnVolumes.get(i));
		}
		
		for(Double value: columnVolumes) {
			volume += value;
		}
		
		
		System.out.println("The volume is: " + volume);
		
	}
}
