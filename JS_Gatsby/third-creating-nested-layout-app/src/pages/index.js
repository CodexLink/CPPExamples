import React from "react";
import Layout from "../components/layout"; // ! Declare Our First Layout Component
// ! Override Imports !
// import { Link } from "gatsby"

// import Layout from "../components/layout"
// import Image from "../components/image"
// import SEO from "../components/seo"

// ! Override Function !
// const IndexPage = () => (
//   <Layout>
//     <SEO title="Home" />
//     <h1>Hi people</h1>
//     <p>Welcome to your new Gatsby site.</p>
//     <p>Now go build something great.</p>
//     <div style={{ maxWidth: `300px`, marginBottom: `1.45rem` }}>
//       <Image />
//     </div>
//     <Link to="/page-2/">Go to page 2</Link>
//   </Layout>
// )

// export default IndexPage

// * Use this one instead.
// ! This is just an introduction on how the plugins work. What being shown here,
// ! Is how TypographyJS generates a CSS Inline Injected in the DOM. The output is inside of the styles
// ! Once reloaded the page. The output literally is the change of font style.

export default () => (
  // ! Encapsulate our HTML with Layout Tag from the Components.
  <Layout>
    <div style={{ margin: `3rem auto`, maxWidth: 600 }}>
      <h1>Hi! I'm building a fake Gatsby site as part of a tutorial!</h1>
      <p>
        What do I like to do? Lots of course but definitely enjoy building
        websites.
    </p>
    </div>
  </Layout>
)