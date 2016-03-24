////
//// Created by 鲁蕴铖 on 16/3/18.
////
//
///**
// * Partitioned merge logic
// *
// * The working core:  each internal node recurses on this function
// * both for its left side and its right side, as nodes one closer to
// * the leaf level.  It then merges the results into the vector passed.
// *
// * Leaf level nodes just sort the vector.
// */
//void partitionedSort ( long *vector, int size, int myHeight, int mySelf )
//{  int parent,
//       rtChild;
//   int nxt;
//
//   parent = mySelf & ~(1 << myHeight);
//   nxt = myHeight - 1;
//   rtChild = mySelf | ( 1 << nxt );
//
//   if ( myHeight > 0 )
//   {
//      int   left_size  = size / 2,
//            right_size = size - left_size;
//      long *leftArray  = (long*) calloc (left_size, sizeof *leftArray),
//           *rightArray = (long*) calloc (right_size, sizeof *rightArray);
//      int   i, j, k;                   // Used in the merge logic
//
//      memcpy (leftArray, vector, left_size*sizeof *leftArray);
//      memcpy (rightArray, vector+left_size, right_size*sizeof *rightArray);
//
//      partitionedSort ( leftArray, left_size, nxt, mySelf );
//      partitionedSort ( rightArray, right_size, nxt, rtChild );
//
//      // Merge the two results back into vector
//      i = j = k = 0;
//      while ( i < left_size && j < right_size )
//         if ( leftArray[i] > rightArray[j])
//            vector[k++] = rightArray[j++];
//         else
//            vector[k++] = leftArray[i++];
//      while ( i < left_size )
//         vector[k++] = leftArray[i++];
//      while ( j < right_size )
//         vector[k++] = rightArray[j++];
//      free(leftArray);  free(rightArray);   // No memory leak!
//   }
//   else
//      qsort( vector, size, sizeof *vector, compare );
//}