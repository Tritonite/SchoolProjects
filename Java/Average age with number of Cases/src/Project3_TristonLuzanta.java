
import java.util.Scanner;

public class Project3_TristonLuzanta {
	/**
	 * Calculates the average age by adding the total number of ages and dividing by
	 * the number of cases.
	 * 
	 * @param Ages
	 * @param check
	 * @return
	 */
	public static int AvgAge(int[] Ages, int check) {
		int total = 0;
		for (int i = 0; i < check; i++) {
			total = total + Ages[i];
		}

		int AvgAge = Math.round(total / check);
		return AvgAge;
	}

	/**
	 * Double the size of the Int array and copy old values to the new one
	 * 
	 * @param Countcheck
	 * @param Ages
	 * @return
	 */
	public static int[] AgesExpand(int Countcheck, int[] Ages) {
		int[] BigAges = null;
		if (Countcheck == Ages.length) {
			BigAges = new int[Ages.length * 2];
			for (int i = 0; i < Ages.length; i++) {
				BigAges[i] = Ages[i];
			}

		}
		return BigAges;

	}

	/**
	 * Double the size of String array and copy old values to the new one
	 * 
	 * @param DiseaseList
	 * @param Countcheck
	 * @return
	 */
	public static String[] ExpandDisease(String[] Disease, int Countcheck) {
		String[] DDisease = null;
		if (Countcheck == Disease.length) {
			DDisease = new String[Disease.length * 2];
			for (int i = 0; i < Disease.length; i++) {

				DDisease[i] = Disease[i];
			}

		}
		return DDisease;
	}

	public static void main(String[] args) {
		Scanner scnr = new Scanner(System.in);
		int cases = 0;
		String[] Diseases = new String[5];
		int[] Ages = new int[5];

		System.out.println("Welcome to the Flu Tracker");
		System.out.println("Type of the name of the Influenza Type (x to exit)");
		String input = scnr.next();

		if (input.equals("x")) {
			System.out.println("Summary information:");
			System.out.println("There were " + cases + " cases of Flu to summarize");
		}

		while ((!input.equals("x"))) {

			Diseases[cases] = input;
			System.out.println("What is the age of the patient?");
			Ages[cases] = scnr.nextInt();
			cases++;
			System.out.println("Next Patient");
			System.out.println("Type of the name of the Influenza Type (x to exit)");
			input = scnr.next();

			/**
			 * Doubles the array size when cases equals the initial array size.
			 */
			if (cases == Diseases.length) {
				String[] result = ExpandDisease(Diseases, cases);
				Diseases = result;
				int[] AgeResult = AgesExpand(cases, Ages);
				Ages = AgeResult;

			}
			if (input.equals("x")) {
				System.out.println("Summary information:");
				for (int i = 0; i < cases; i++) {
					System.out.println("Type:" + Diseases[i] + "\t" + " Age: " + Ages[i]);

				}
				/*
				 * Prints out the number of cases and the average age among the cases.
				 */
				System.out.println(
						"There were: " + cases + " cases of influenza with an average age of " + AvgAge(Ages, cases));

			}

		}
	}
}
