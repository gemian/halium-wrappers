/*
 * Reserve some space into the Thread Local Storage so that
 * bionic has more leeway.
 *
 * Shout-out to Ratchanan Srirattanamet from ubports!
*/

__thread void *padding[16];
