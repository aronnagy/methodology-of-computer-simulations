package paraboloidVolume;

import java.util.ArrayList;
import java.util.Random;

public class RandomShooter {
	
	static double subShooting(ArrayList<Double> x, ArrayList<Double> y, ArrayList<Double> realValues, ArrayList<Double> guessedValues) {
		double success = 0;
		double volume = 0;
		for(int i = 0; i < x.size(); i++) {
			realValues.add(x.get(i)*x.get(i)+y.get(i)*y.get(i));
			//System.out.println("(x: " + x.get(i) + " y: " + y.get(i) + ") = " + (x.get(i)*x.get(i)+y.get(i)*y.get(i)));
			//System.out.println("GUESS: " + guessedValues.get(i));
			if(guessedValues.get(i) > realValues.get(i)) {
			} else success++;
		}
		
		volume = success/(10)*216;
		
		return volume*3;
	}
	
	static double shooting(ArrayList<Double> x, ArrayList<Double> y, ArrayList<Double> realValues, ArrayList<Double> guessedValues, double n) {
		double success = 0;
		double volume = 0;
		for(int i = 0; i < x.size(); i++) {
			realValues.add(x.get(i)*x.get(i)+y.get(i)*y.get(i));
			//System.out.println("(x: " + x.get(i) + " y: " + y.get(i) + ") = " + (x.get(i)*x.get(i)+y.get(i)*y.get(i)));
			//System.out.println("GUESS: " + guessedValues.get(i));
			if(guessedValues.get(i) > realValues.get(i)) {
			} else success++;
		}
		
		volume = success/(guessedValues.size())*216;
		
		return volume;
	}


	public static double getRandomDoubleBetweenRange(double min, double max){
		double x = (Math.random()*((max-min)+1))+min;
		return x;
	}
	
	public static void main(String args[]) {
		
		double n = 1000000;
		double deviation = 0;
		double sumOfSubVolumes = 0;
		double averageVolume = 0;
		double volume = 0;
		
		ArrayList<Double> guessedValues = new ArrayList<Double>();
		ArrayList<Double> x = new ArrayList<Double>();
		ArrayList<Double> y = new ArrayList<Double>();
		ArrayList<Double> X = new ArrayList<Double>();
		ArrayList<Double> Y = new ArrayList<Double>();
		ArrayList<Double> allGuessedValues = new ArrayList<Double>();
		ArrayList<Double> realValues = new ArrayList<Double>();
		ArrayList<Double> subVolumeValues = new ArrayList<Double>();	
		
		for(int j = 0; j < n; j++) {
			
			for(int i = 0; i < 10; i++) {
				 x.add(getRandomDoubleBetweenRange(-3.0,2.0));
				 y.add(getRandomDoubleBetweenRange(-3.0,2.0));
				 guessedValues.add(getRandomDoubleBetweenRange(0,17));
			}
			
			sumOfSubVolumes += subShooting(x, y, realValues, guessedValues);
			subVolumeValues.add(subShooting(x, y, realValues, guessedValues));
			
			X.addAll(x);
			Y.addAll(y);
			allGuessedValues.addAll(guessedValues);
			
			x.clear();
			y.clear();
			guessedValues.clear();

		}
		
		volume = shooting(X, Y, realValues, allGuessedValues, n)*3;
		
		averageVolume = sumOfSubVolumes/n;
		
		for(int i = 0; i < n; i++) {
			deviation += Math.abs(subVolumeValues.get(i)-averageVolume)/n;
		}
		
		deviation = deviation/n;

		System.out.println("The volume after " + n*10 + " shoots: " + volume);
		System.out.println("The average volume after 10x" + n + " shoots: " + averageVolume);
		System.out.println("Deviation at this point: " + Math.sqrt(deviation));
		
	}

}
