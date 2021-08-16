import React from 'react';
import Layout from "../components/layout"; // ! Declare Our First Layout Component

// ! This is literally a JSX. THe use of JSX extension in the pages folder is optional.
export default () => (
    <Layout>
        <div>
            <h1>About me</h1>
            <p>I’m good enough, I’m smart enough, and gosh darn it, people like me!</p>
        </div>
    </Layout>
)