public class BoundedBuffer {

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
      notifyAll(); // in case any retrieves are waiting for data, wake them
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
      notifyAll(); // in case any retrieves are waiting for data, wake them
      return retrieved;

   }
}