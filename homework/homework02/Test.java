import java.util.Random;

public class Test implements Runnable {

	Object objectTest;
	BoundedBuffer boundedBuffer;

	public Test(Object parameter, BoundedBuffer bb, Random rand) {

		objectTest = parameter;
		boundedBuffer = bb;

	}

	public static void main(String[] args) throws InterruptedException {

		Object obj = new String("Word");

		Random rand = new Random();
		BoundedBuffer bb = new BoundedBuffer();
		for (int i = 0; i < 200; i++) {

			Runnable r = new Test(obj, bb, rand);
			new Thread(r).start();

		}

	}

	public void run() {

		try {
			boundedBuffer.insert(objectTest);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		try {
			boundedBuffer.retrieve();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}