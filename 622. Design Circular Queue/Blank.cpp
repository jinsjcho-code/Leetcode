// ===== Practice (CoderPad style): 622. Design Circular Queue =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]  Design a circular queue (ring buffer) of fixed capacity k.
//   - MyCircularQueue(int k)
//   - bool enQueue(int value): insert at rear. false if full.
//   - bool deQueue():          delete from front. false if empty.
//   - int  Front():            front value, or -1 if empty.
//   - int  Rear():             rear value,  or -1 if empty.
//   - bool isEmpty();
//   - bool isFull();
//
//   Example:
//     MyCircularQueue q(3);
//     q.enQueue(1) -> true
//     q.enQueue(2) -> true
//     q.enQueue(3) -> true
//     q.enQueue(4) -> false   (full)
//     q.Rear()     -> 3
//     q.isFull()   -> true
//     q.deQueue()  -> true
//     q.enQueue(4) -> true
//     q.Rear()     -> 4
//
// Idea: fixed-size array + head index + count.
//   - store: vector<int> buf(k), int head=0, int count=0, int cap=k
//   - tail position = (head + count) % cap   <-- WRAPAROUND with %
//   - enQueue: buf[(head+count)%cap]=value; count++
//   - deQueue: head=(head+1)%cap; count--
//   - Front = buf[head];  Rear = buf[(head+count-1)%cap]
//
// Hardware angle: "This is a hardware FIFO - producer writes at the tail,
//   consumer reads at the head, fixed buffer with wraparound."
//
// This is "state" -> MEMBER variables.
//
// Start from a blank slate below:


