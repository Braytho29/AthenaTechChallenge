# AthenaTechChallenge
 This repo houses the UE project and functions for the Athena Technical Challenge.

 If the level does not open by default, the directory path is: /Content/Level/AthenaTechChallenge.umap
 
 The project will also need to be compiled and built at runtime.

 The steps that have been completed are: 1, 2, 3, 4, 5, 8

 For step 8, the code is located in /FIFOCache
 I have created a Cache that follows a First In First Out Eviction policy.
 The eviction policy of the cache would change to suit the purpose of the task, but I am assuming that the cache 
 will be used to store the most recent images captured from a camera in UE and use these images for tasks such 
 as computer vision. Therefore, the cache will always be storing the 10 most recent images and there will no longer
 be a need to store older images as the task will have already used them. 