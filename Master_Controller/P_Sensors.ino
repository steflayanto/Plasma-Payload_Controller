void initTempSens() {
  tempSens.begin();
  Serial.print("TempSensor Initialized");
}

// SETUP Code
void initLSM() {
  Serial.print("Setting up LSM9DS0 IMU... ");
  if (!lsm.begin()) {
    Serial.println("ERROR: Unable to initialize sensor. Check wiring.");
    while (1);
  }
  Serial.println("Success.");

  // 1.) Set the accelerometer range
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}



float tempSensTemp() {
  return tempSens.readTempF();
}

float LSMaccelX() {
  return accel.acceleration.x;
}

float LSMaccelY() {
  return accel.acceleration.y;
}

float LSMaccelZ() {
  return accel.acceleration.z;
}

float LSMmagX() {
  return mag.magnetic.x;
}

float LSMmagY() {
  return mag.magnetic.y;
}

float LSMmagZ() {
  return mag.magnetic.z;
}

float LSMgyroX() {
  return gyro.gyro.x;
}

float LSMgyroY() {
  return gyro.gyro.y;
}

float LSMgyroZ() {
  return gyro.gyro.z;
}

float LSMtemp(){
  return temp.temperature;
}
