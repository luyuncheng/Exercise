package Future_Promise;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import javax.swing.plaf.FontUIResource;

public class MatrixThread {
	int dim;
	double[][] data;
	int rowDisplace, colDisplace;
	public MatrixThread(int d) {
		dim = d;
		rowDisplace = colDisplace = 0;
		data = new double[d][d];
	}
	
	private MatrixThread(double[][] matrix, int x, int y, int d) {
		data = matrix;
		rowDisplace = x;
		colDisplace = y;
		dim = d;
	}
	
	public double get(int row, int col) {
		return data[row + rowDisplace][col + colDisplace];
	}
	public void set(int row, int col, double value) {
		data[row + rowDisplace][col + colDisplace] = value;
	}
	public int getDim() {
		return dim;
	}
	MatrixThread[][] split() {
		MatrixThread[][] result = new MatrixThread[2][2];
		int newDim = dim / 2;
		result[0][0] = new MatrixThread(data, rowDisplace, colDisplace, newDim);
		result[0][1] = new MatrixThread(data, rowDisplace, colDisplace + newDim, newDim);
		result[1][0] = new MatrixThread(data, rowDisplace + newDim, colDisplace, newDim);
		result[1][1] = new MatrixThread(data, rowDisplace + newDim, colDisplace + newDim, newDim);
		return result;
	}
	
	
	public static class MatrixTask {
		static ExecutorService exec = Executors.newCachedThreadPool();
		static MatrixThread add(MatrixThread a, MatrixThread b) throws ExecutionException {
			int n = a.getDim();
			MatrixThread c = new MatrixThread(n);
			Future<?> future = exec.submit(new AddTask(a, b, c));
			try {
				future.get();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return c;
		}
		// 多线程加法
		public static class AddTask implements Runnable {
			MatrixThread a, b, c;
			public AddTask(MatrixThread myA, MatrixThread myB, MatrixThread myC) {
				a = myA; b = myB; c = myC;
			}
			
			public void run() {
				try {
					int n = a.getDim();
					if (n == 1) {
						c.set(0, 0, a.get(0, 0) + b.get(0, 0));
					} else {
						MatrixThread[][] aa = a.split(), bb = b.split(), cc = c.split();
						Future<?>[][] future = (Future<?>[][]) new Future[2][2];
						for(int i = 0; i < 2; i++)
							for(int j = 0; j < 2; j++)
								future[i][j] = exec.submit(new AddTask(aa[i][j], bb[i][j], cc[i][j]));
						for(int i = 0; i < 2; i++)
							for(int j = 0; j < 2; j++)
								future[i][j].get();
					}
				} catch (Exception ex) {
					ex.printStackTrace();
				}
			}
			
			
		}
		// 多线程乘法
		public static class MulTask implements Runnable {
			MatrixThread a, b, c, lhs, rhs;
			public MulTask(MatrixThread myA, MatrixThread myB, MatrixThread myC) {
				a = myA; b = myB; c= myC;
				lhs = new MatrixThread(a.getDim());
				rhs = new MatrixThread(b.getDim());
			}
			public void run() {
				try {
					if(a.getDim() == 1) {
						c.set(0, 0, a.get(0, 0) * b.get(0,0));
					} else {
						MatrixThread[][] aa = a.split(), bb = b.split(), cc = c.split();
						MatrixThread[][] ll = lhs.split(), rr = rhs.split();
						Future<?>[][][] future = (Future<?>[][][]) new Future[2][2][2];
						for(int i = 0; i < 2; i++)
							for(int j = 0; j < 2; j++) {
								future[i][j][0] = exec.submit(new MulTask(aa[i][0], bb[0][i], ll[i][j]));
								future[i][j][1] = exec.submit(new MulTask(aa[1][i], bb[i][1], rr[i][j]));
							}
						for(int i = 0; i < 2; i++) 
							for(int j = 0; j < 2; j++)
								for(int k = 0; k < 2; k++) {
									future[i][j][k].get();
								}
						Future<?> done = exec.submit(new AddTask(lhs, rhs, c));
						done.get();
					}
				} catch (Exception ex) {
					ex.printStackTrace();
				}
			}
		}
	}
	//Fib
	static class FibTask implements Callable<Integer> {
		static ExecutorService exec = Executors.newCachedThreadPool();
		int arg;
		public FibTask(int n) {
			arg = n;
		}
		public Integer call() throws InterruptedException, ExecutionException {
			if(arg > 2) {
				Future<Integer> left = exec.submit(new FibTask(arg-1));
				Future<Integer> right = exec.submit(new FibTask(arg-2));
				return left.get() + right.get();
			} else {
				return 1;
			}
		}
	}
	
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		int n = 50;

		long startTime=System.currentTimeMillis();   //开始时间
		
		FibTask fib = new FibTask(n);
		System.out.println(fib.call());

		long endTime=System.currentTimeMillis(); //获取结束时间
		System.out.println("multi线程程序运行时间： "+(endTime-startTime)+"ms");
		
		
		startTime=System.currentTimeMillis();   //开始时间
		int a1 = 1, a2 = 1, a = 0;
		for(int i = 3; i <= n; i++) {
			a = a1 + a2;
			a1 = a2;
			a2 = a;
		}
		System.out.println(a);
		endTime=System.currentTimeMillis(); //获取结束时间
		System.out.println("single线程程序运行时间： "+(endTime-startTime)+"ms");
	}

}

