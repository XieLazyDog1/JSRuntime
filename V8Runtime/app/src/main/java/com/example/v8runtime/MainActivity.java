package com.example.v8runtime;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.v8runtime.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'v8runtime' library on application startup.

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        JSRuntime.getInstance(this);


        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText("JSRuntime");

    }


}