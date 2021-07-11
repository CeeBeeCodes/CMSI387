public class BoundedBuffer_Modify {
	private Object[] buffer = new Object[3]; // arbitrary size
	private int numOccupied = 0;
	private int firstOccupied = 0;

	public synchronized void insert(Object o) throws InterruptedException {
		while (numOccupied == buffer.length) {
			System.out.println("waiting to insert: " + o.toString());
			wait(); // wait for space
		}
		buffer[(firstOccupied + numOccupied) % buffer.length] = o;
		System.out.println("inserted: " + o.toString());
		numOccupied++;
		if (numOccupied == 1) {
			notifyAll();
		}

	}

	public synchronized Object retrieve() throws InterruptedException {

		while (numOccupied == buffer.length) {
			System.out.println("waiting to retreive: " + buffer[firstOccupied].toString());
			wait(); // wait for space
		}

		Object retrieved = buffer[firstOccupied];
		System.out.println("retreived: " + retrieved.toString());
		buffer[firstOccupied] = null; // may help garbage collector
		firstOccupied = (firstOccupied + 1) % buffer.length;
		numOccupied--;
		if (numOccupied == 3) {
			notifyAll();
		}

		return retrieved;

	}
}