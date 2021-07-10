import java.util.Scanner;

public class Project4_TristonLuzanta {

	// Sorts the ages from youngest to oldest using a selection sort
	public static void sortAges(int[] ages, int sizes, String[] flu) {
		int tempAge;
		String tempFlu;
		int small;

		for (int i = 0; i < ages.length - 1; i++) {

			small = i;

			for (int j = i + 1; j < ages.length; j++) {
				if (ages[j] < ages[small]) {
					small = j;

				}

			}

			tempFlu = flu[small];
			flu[small] = flu[i];
			flu[i] = tempFlu;

			tempAge = ages[small];
			ages[small] = ages[i];
			ages[i] = tempAge;

		}

	}

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);
		int cases = 0;
		String[] flu = new String[20]; // Stores up to 20 flu types
		int[] ages = new int[20]; // Stores up to 20 patients ages
		sortAges(ages, cases, flu);

		System.out.println("Welcome to the Flue Tracker");
		System.out.println("Type the name of the Influenza Type (x to exit)");
		String type = scn.next();

		if (type.equals("x")) {
			System.out.println("Summary Information:");
			System.out.println("There were: " + cases + " cases of Flu to summarize");
		}
		// Inputs the age and flu types when user does not hit x.
		while (!type.equals("x")) {

			flu[cases] = type;

			System.out.println("What is the age of the patient?");

			ages[cases] = scn.nextInt();

			cases++;
			System.out.println("Next Patient");
			System.out.println("Type of the name of the Influenza Type (x to exit)");
			type = scn.next();
			// Displays the age and flu types by age when user hits x.
			if (type.equals("x")) {
				System.out.println("Summary Information:");

				sortAges(ages, cases, flu); // Calls the method to sort ages and flu

				for (int i = 0; i < cases; i++) {
					System.out.println("Type: " + flu[i] + "\t" + ages[i]);

				}

				// System.out.println(Arrays.toString(ages));
				// System.out.println(Arrays.toString(flu));
			}

		}

	}
}
