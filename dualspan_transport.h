#include <$HIP\inc.h>

//connections
float test [] = detail(0, "test"); 

f[]@alpha; 
int root = 0; 
@alpha[0] = 0; 
float beta = 0; 
i[]@que; 
push(@que, root); 

while (len(i[]@que) != 0) {
  
   int next_prim = pop(i[]@que);
   int hedge = primhedge(0, next_prim);
   int equiv = primhedge(0, next_prim);
            
   do {
           
        int edge  = hedge_nextequiv(0, equiv);
        int face_i = hedge_prim(0,equiv);
        int face_j = hedge_prim(0,edge);
     
        if ( i[]@parent[face_j] == face_j && face_j != root) 
        {
                                  
                 //printf("%f %f %f\n",face_i, face_j,edgeid ); 
                 
                    int edgeid = edgenmr(edge); 
                                                            
                    float phi = test[edgeid]; 
                    
                    vector vedge = vectorhedge(edge);
                                        
                 // vedge = vectorhedge(chi("edgenmr"));
                                       
                    float sign = signs(edge);

          
                    vedge = vedge * sign; 
                    phi *= sign; 

          
                    vector e1, e2; 
                    
                    gram_schmidt( face_i , e1, e2); 
                                     
                    
                    float deltaij = atan2(dot(vedge, e2) , dot(vedge, e1));  
                    
                    gram_schmidt( face_j , e1, e2); 
                    
                    float deltaji = atan2(dot(vedge, e2) , dot(vedge, e1));
              
                                                                          
                   f[]@alpha[face_j] = (f[]@alpha[face_i] - deltaij + deltaji)-phi; 

          
                    
                   i[]@parent[face_j] = face_i; 
                                                       
                   push(i[]@que, face_j); 
                 
                                        
         } 

                 
        equiv = hedge_next(0,equiv);
     
      } 
                                    
    while(equiv != hedge);
   
  
  
  } 
  
  
  

  
  
